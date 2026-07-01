pipeline {

    agent any

    stages {

        stage('Compilar') {

            steps {

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe'

            }

        }

        stage('Analisis SonarCloud') {

            steps {

                withSonarQubeEnv('SonarCloud') {

                    bat 'sonar-scanner'

                }

            }

        }

    }

}