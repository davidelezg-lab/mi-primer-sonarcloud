pipeline {

    agent any

    stages {

        stage('Compilar') {
            steps {
                bat '''
                "C:/msys64/ucrt64/bin/g++.exe" main.cpp -o app.exe

                if errorlevel 1 exit /b 1
                '''
            }
        }

        stage('Ejecutar') {
            steps {
                bat '''
                app.exe > resultado.txt

                type resultado.txt

                findstr "30" resultado.txt

                if errorlevel 1 exit /b 1
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
        success {
            echo 'Pipeline correcta'
        }
        failure {
            echo 'Pipeline fallida'
        }
    }
}