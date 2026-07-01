pipeline {

    agent any

    stages {

        stage('Compilar') {

            steps {

                bat '''
                "C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe

                if exist app.exe (
                    echo COMPILACION CORRECTA
                ) else (
                    echo ERROR: app.exe no generado
                    exit /b 1
                )
                '''
            }
        }

    }

}
