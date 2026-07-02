pipeline {

    agent any

    stages {

        stage('Compilar') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                "C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe

                if not exist app.exe exit /b 1
                '''
            }
        }

        stage('Ejecutar programa') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                app.exe
                '''
            }
        }

        stage('Test') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                echo ===== TEST NUEVO =====

                "C:\\msys64\\ucrt64\\bin\\g++.exe" test.cpp -o test.exe

                if not exist test.exe exit /b 1

                test.exe
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