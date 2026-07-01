pipeline {

    agent any

    stages {

        stage('Compilar') {

            steps {

                bat 'g++ main.cpp -o app.exe'

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