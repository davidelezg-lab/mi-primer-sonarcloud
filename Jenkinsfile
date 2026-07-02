pipeline {

    agent any

    stages {

        stage('Mostrar codigo fuente') {
            steps {
                bat '''
                echo =====================
                echo CONTENIDO MAIN.CPP
                echo =====================

                type main.cpp

                echo =====================
                '''
            }
        }

        stage('Compilar') {
            steps {
                bat '''
                "C:/msys64/ucrt64/bin/g++.exe" main.cpp -o app.exe

                if not exist app.exe exit /b 1

                dir app.exe

                exit /b 0
                '''
            }
        }

        stage('Ejecutar y comprobar resultado') {
            steps {
                bat '''
                echo =====================
                echo EJECUTANDO APP
                echo =====================

                app.exe

                app.exe > resultado.txt

                echo =====================
                echo CONTENIDO RESULTADO.TXT
                echo =====================

                type resultado.txt

                echo =====================
                echo BUSCANDO 30
                echo =====================

                findstr "30" resultado.txt

                if errorlevel 1 (
                    echo ERROR: No se encontro el valor 30
                    exit /b 1
                )

                exit /b 0
                '''
            }
        }

        stage('Analisis SonarCloud') {
            steps {
                withSonarQubeEnv('SonarCloud') {
                    bat '''
                    "C:/sonar-scanner/bin/sonar-scanner.bat"
                    '''
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

        always {
            echo 'Fin de la ejecucion'
        }

        success {
            echo 'Pipeline correcta'
        }

        failure {
            echo 'Pipeline fallida'
        }
    }
}