pipeline {

    agent any

    stages {

        stage('Compilar Aplicacion') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                "C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp suma.cpp -o app.exe

                if not exist app.exe exit /b 1
                '''
            }
        }

        stage('Ejecutar Aplicacion') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                app.exe
                '''
            }
        }

        stage('Compilar Test con Cobertura') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                "C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage suma.cpp test.cpp -o test.exe

                if not exist test.exe exit /b 1
                '''
            }
        }

        stage('Ejecutar Test') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                test.exe
                '''
            }
        }

        stage('Generar Cobertura') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                gcov suma.cpp

                echo ===== ARCHIVOS GCOV =====

                dir *.gcov
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