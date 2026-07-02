pipeline {

    agent any

    stages {

        stage('Compilar') {
            steps {
                bat '''
                echo ===== MAIN.CPP =====
                type main.cpp
                echo ====================

                "C:/msys64/ucrt64/bin/g++.exe" main.cpp -o app.exe

                echo CODIGO_ERROR=%ERRORLEVEL%

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
                '''
            }
        }
    }

    post {
        always {
            echo 'Fin de la ejecucion'
        }
    }
}