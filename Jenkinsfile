pipeline {

    agent any

    stages {

        stage('Compilar') {
            steps {
                bat '''
                echo ===== MAIN.CPP =====
                type main.cpp
                echo ====================

                "C:/msys64/ucrt64/bin/g++.exe" main.cpp -o app.exe 2> error.txt

                echo ===== ERRORES COMPILACION =====

                type error.txt

                echo ==============================

                exit /b 0
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