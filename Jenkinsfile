pipeline {

    agent any

    stages {

        stage('Compilar') {

            steps {

                bat '''
                echo ==== DIRECTORIO ====
                dir

                echo.
                echo ==== CONTENIDO MAIN.CPP ====
                type main.cpp

                echo.
                echo ==== VERSION G++ ====
                "C:\\msys64\\ucrt64\\bin\\g++.exe" --version

                echo.
                echo ==== COMPILANDO ====
                "C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe 2> error.txt

                echo.
                echo ==== ERROR DE COMPILACION ====
                type error.txt

                echo.
                echo ==== CODIGO RETORNO ====
                echo ERRORLEVEL=%ERRORLEVEL%

                echo.
                echo ==== FICHEROS GENERADOS ====
                dir
                '''
            }
        }

    }

}