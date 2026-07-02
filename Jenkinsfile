pipeline {

    agent any

    stages {

        stage('Mostrar codigo fuente') {
            steps {
                bat '''
                type main.cpp
                '''
            }
        }

        stage('Compilar') {
            steps {
                bat '''
                "C:/msys64/ucrt64/bin/g++.exe" main.cpp -o app.exe

                if errorlevel 1 exit /b 1

                dir app.exe
                '''
            }
        }

        stage('Ejecutar') {
            steps {
                bat '''
                app.exe

                app.exe > resultado.txt

                echo ===== RESULTADO =====
                type resultado.txt
                echo =====================
                '''
            }
        }

        stage('Validar resultado') {
            steps {
                bat '''
                findstr "30" resultado.txt

                if errorlevel 1 (
                    echo No se encontro 30
                    exit /b 1
                )
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