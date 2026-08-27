# renergieCH
Programme intuitif ayant pour but d'informer les propriétaires et professionnels sur les aspects énergétiques de leurs projets de rénovation


## Le programme
### Public cible
Ce programme est conçu pour les
- architectes
- propriétaires
- maîtres d'ouvrage
- ingénieurs
- tout autre personne concernée par un projet de rénovation immobilier

### But
Le but de ce programme est de proposer une interface intuitive pour établir aussi clairement que possible les exigences rattachées à un projet de rénovation en fonction de ses spécificités.

## Code source
### Arborescence des fichiers
Le projet aurait 4 principaux répertoires de code :
- préprocesseur

- reçoit des entrées de l'utilisateur et génère une entrée pour le solveur

- permet de sauvegarder l'entrée pour la récupérer plus tard
- solveur
- utilise les arguments créés par le préprocesseur

- post-traitement

- permet d'imprimer, d'afficher et de sauvegarder les résultats
- interface graphique
- interface graphique pour le pré-processeur, le solveur et le post-processeur

### Bibliothèques et outils utilisés
- Commandes de compilation : [**CMake**] (https://cmake.org/)
- Windows : [**Qt**] (https://www.qt.io/)
- Graphiques : [**OpenGL**] (https://www.opengl.org/)
- Documentation du code : [**doxygen**](https://doxygen.nl/)
- Algèbre linéaire : [**Eigen**](https://eigen.tuxfamily.org/)
- Tests unitaires : [**Catch2**] (https://github.com/catchorg/Catch2)

## Comment compiler le projet et les fichiers associés
### Acquisition des fichiers
#### Pour les non-collaborateurs
Il suffit de forker le dépôt sur votre propre GitHub. Vous pouvez alors travailler sur cette version forkée. Une fois que les modifications sur le dépôt forké sont toutes poussées, vous pouvez effectuer une pull request vers le dépôt original, que les administrateurs examineront.
#### Pour les collaborateurs
1. Vous pouvez utiliser la méthode décrite ci-dessus pour les non-collaborateurs.
2. Vous pouvez créer une branche personnelle dans laquelle vous apportez vos modifications. Une fois les modifications effectuées, vous pouvez faire une demande de tirage pour fusionner avec la branche parente. Assurez-vous de créer une branche par sujet de modification. Évitez d'utiliser une seule branche pour des modifications qui ne sont pas liées entre elles. De plus, nommez-le de manière à ce que nous comprenions de quoi il s'agit. Par exemple, `preprocessor-grid` traiterait spécifiquement de la classe `Grid` du `preprocessor`, tandis que `preprocessor-general` serait plus général par nature.

### Acquisition des bibliothèques requises
Avant de compiler le projet, vous devez avoir installé sur votre ordinateur
1. CMake
2. doxygen
3. Qt Creator

En général, l'installateur de Qt Creator a l'option d'installer également OpenGL. Si vous n'installez pas OpenGL de cette manière, assurez-vous de l'avoir installé séparément.

Les bibliothèques C++ seront acquises au moment de la compilation en suivant les instructions du fichier `CMakeLists.txt`.

### Compilation du projet
Le projet est compilé en utilisant CMake et les instructions contenues dans `CMakeLists.txt`. Vous pouvez soit le compiler en utilisant l'interface graphique de Qt Creator, soit en utilisant des commandes dans le terminal.
#### Utilisation de l'interface graphique de Qt Creator
1. Pour compiler le projet, ouvrez-le dans Qt Creator.
2. Une fois ouvert, allez dans "Compiler" dans le ruban supérieur, puis "Compiler le projet muri". Sur Windows, le raccourci est Ctrl+B.
3. Une fois compilé, le projet peut être exécuté en utilisant "Exécuter" dans le même menu. Sous Windows, le raccourci est Ctrl+R.

La fenêtre principale doit s'ouvrir et afficher un résultat similaire à la figure ci-dessous.

![Capture d'écran de la fenêtre principale](assets/mainwindow. PNG "Fenêtre principale")

Vous pouvez changer l'exécutable de lancement en
1. Aller à "Projets" dans le ruban vertical à gauche de Qt Creator.
2. Dans "Exécuter", définir "Configuration d'exécution" sur un autre exécutable, comme un fichier de test unitaire par exemple.

#### Utilisation des commandes dans le terminal
Il n'est pas conseillé de compiler et d'exécuter le projet depuis le terminal car le processus peut être fastidieux et facilement mener à des erreurs.

### Compilation de la documentation
Pour compiler la documentation, ouvrez un terminal à la racine de ce dépôt et tapez
```
doxygen
```
Allez dans le dossier `html` à la racine de ce dépôt et ouvrez le fichier `index.html` avec un navigateur web par exemple. Cela vous mènera à la page principale de la documentation. Vous pouvez ensuite naviguer à travers les différents éléments de code du projet.


## Comment contribuer
Il existe de nombreuses façons de contribuer à ce projet :
- Écrire du code
- Réviser le code et suggérer des modifications/améliorations
- Créer des tests unitaires et les exécuter
- Rédiger et affiner la documentation
- Fournir des illustrations pour le logiciel

N'hésitez pas à nous contacter si vous souhaitez contribuer d'une manière différente de celles mentionnées ci-dessus.
