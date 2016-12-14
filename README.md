# reddit-Analysis

## Introduction
L’équipe est composée de 5 membres :
* Nathan KREMER [@xD3VHAX](https://github.com/xD3VHAX),
* Thomas CARDONNE [@SmurfyFR](https://github.com/SmurfyFR),
* Sabri M’BARKI,
* Marius DAUPHIN,
* Rayan BOUSLAMA.

Ce projet permet d'effectuer des statistiques sur les "data dump" du site Reddit.com.

Celui-ci est découpé en deux parties :
* Une partie "serveur", dévelopée en Python, qui permet de convertir et nettoyer les données récupérées sur différents torrents, situé dans le répertoire `/server`
* Une partie "cliente", développée en C++, qui effectue les statistiques à partir des fichiers JSON ainsi nettoyés. (répertoire `client`)

Ces deux parties sont indépendantes.

## Mirroir HTTP
L'application cliente peut récupérer des fichiers précedemment nettoyés par nos soins sur un mirroir. Ce mirroir est disponible à l'adresse suivante : http://89.234.183.123/reddit.

Il contient les "dump" complets de Octobre 2007 à Mai 2010 ainsi qu'un fichier de test `RC_2007-10_2kItems.json` contenant 2000 lignes aléatoirement tirés du fichier de Octobre 2007. Ce dernier fichier est inclu dans le repository GitHub.

## Installation
Récupération des sources via git : `git clone git@github.com:xD3VHAX/reddit-Analysis.git`

### Installation - Partie serveur
Le programme "serveur" développé en Python nécessite :
    * Python (évidemment) dans sa version 2.7.9,
    * L'installation du module Python ujson (via pip : `pip install ujson`).

### Installation - Partie client
Le programme "client" développé en C++ nécessite l'installation de QtCreator.
Après l'installation de QtCreator, après ouverture du projet et la première compilation, il sera nécessaire de copier les dossiers `images` et `data` dans le dossier "Debug" ou "Release" généralement situé dans le dossier parent du répertoire `client` (du projet) (dans le dossier `build-Boum-Desktop_Qt_5_6_0_MinGW_32bit-Debug`, par exemple).

### Utilisation
Un manuel d'utilisation est disponible dans le fichier `USER_MANUAL.md`
