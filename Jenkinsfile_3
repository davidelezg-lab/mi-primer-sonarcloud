pipeline {

    agent any

    stages {

        stage('Compilar') {

            steps {

                bat '''
                "C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe

                if not exist app.exe exit /b 1

                exit /b 0
                '''
            }
        }

        stage('Ejecutar programa') {

            steps {

                bat '''
                echo ===== PATH ACTUAL =====
                echo %PATH%

                echo.
                echo ===== APP.EXE =====
                dir app.exe

                echo.
                echo ===== ANIADIENDO DLLS DE MSYS2 =====

                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                echo.
                echo ===== EJECUTANDO PROGRAMA =====

                app.exe
                '''
            }
        }

        stage('Analisis SonarCloud') {

            steps {

                withSonarQubeEnv('SonarCloud') {

                    bat '"C:\\sonar-scanner\\bin\\sonar-scanner.bat"'

                }

            }
        }

        stage('Quality Gate') {

            steps {

                timeout(time: 5, unit: 'MINUTES') {

                    waitForQualityGate abortPipeline: true

                }

            }
        }

    }

    post {

        success {

            echo 'Pipeline completada correctamente'

        }

        failure {

            echo 'Pipeline fallida'

        }

        aborted {

            echo 'Pipeline abortada'

        }

        always {

            echo 'Fin de la ejecucion'

        }
    }
}