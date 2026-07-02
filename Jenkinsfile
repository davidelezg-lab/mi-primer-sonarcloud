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

                echo ===== GCNO =====
                dir *.gcno

                echo ===== GCDA =====
                dir *.gcda
                '''
            }
        }

        stage('Ejecutar Test') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                test.exe

                echo ===== GCNO DESPUES DEL TEST =====
                dir *.gcno

                echo ===== GCDA DESPUES DEL TEST =====
                dir *.gcda
                '''
            }
        }

        stage('Generar Cobertura') {

            steps {

                bat '''
                set PATH=C:\\msys64\\ucrt64\\bin;%PATH%

                echo ===== FICHEROS DEL DIRECTORIO =====

                dir

                echo ===== GCNO =====
                dir *.gcno

                echo ===== GCDA =====
                dir *.gcda
                '''
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

        always {
            echo 'Fin de la ejecucion'
        }
    }
}