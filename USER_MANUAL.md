# Manuel d'utilisation

## Programme Python (serveur)
Le programme écrira les fichiers de sortie dans le répertoire out/ (relatif au dossier d'execution de sanitize.py).

Nettoyer un fichier : `./sanitize.py raw/file.bz2`.
Nettoyer plusieurs fichiers : `./sanitize.py raw/file.bz2 raw/file-second.bz2`.

Options :
* `-d` ou `--debug` : Permet de ne traiter que 2000 lignes,
* `-p` ou `--progress` : Calcule la taille du fichier d'entrée afin de donner un retour en temps réel sur l'avancement,
* `-v` ou `--verbose` : Affiche l'id de chaque message traité.

## Application cliente
Le programme affiche lors de son lancement un ensemble de bouton dans la partie supérieure de la fenêtre ainsi qu'une barre indiquant
la quantité de mémoire utilisée sur votre ordinateur. Il est important d'avoir de la mémoire libre si vous prévoyez de charger de gros fichiers.

### Chargement d'un fichier
La liste déroulante contenant "Select file" vous permet de choisir un fichier sur lequel effectuer les différentes statistiques.
Les fichiers jaunes sont ceux disponibles sur le mirroir distant, et seront donc téléchargés, et les fichiers blancs sont les fichiers disponibles en local sur votre ordinateur dans le dossier `data/` (ou déjà téléchargé précedemment).

Le bouton `Reload Files` permet de recharger la liste des fichiers et le bouton `Abort` permet d'arrêter le chargement d'un fichier.

### Boutons "Get *"
L'ensemble des boutons "Get *" (ie : Get Posts by hours) vous permet de lancer une fonction d'analyse sur le fichier précedemment choisi.

* `Get Posts by days` : Affiche le nombre de commentaires par jour (de 1 à 31),
* `Get Posts by hours` : Affiche le nombre de commentaires par heure (de 0 à 24),
* `Get topics by month` : Affiche le nombre de nouveaux "topics" (ou sujets) par mois,
* `Get messages by users` : Affiche le nombre de message par utilisateur (et les identifiants de ceux-ci).

Les résultats sont affichés dans la boîte de texte centrale. Le bouton `Clean output` permet de vider cette boîte de texte.

### Reports
Si l'option `Generate reports ?`, le programme enregistrera dans le dossier courant les statistiques obtenues par les fonctions `Get Posts by days`, `Get Posts by hours` et `Get messages by users`.
Ces données sont enregistrées au format CSV et peuvent être ainsi utilisés pour générer des graphiques à l'aide de Excel ou Google Sheets.
