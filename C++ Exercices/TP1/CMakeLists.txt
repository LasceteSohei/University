cmake_minimum_required(VERSION 3.0)

#Déclaration du projet
project(TP1_C++)

#On crée un répertoire pour les binary de sortie
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Recherche des fichiers sources dans le dossier src
file(
	GLOB_RECURSE

	source_files

	src/*
)

add_executable(
	toto

	${source_files}
)
