pipeline {

    agent any

    stages {

        stage('Compilar') {

            steps {

                bat '''
                "C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe

                dir *.exe

                if not exist app.exe exit /b 1

                exit /b 0
                '''
            }
        }

    }

}
