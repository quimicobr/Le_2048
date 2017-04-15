# Le_2048
Jeu 2048 codé en langage C++ utilisant QT.

Projet des élèves : Lucas CARDOSO VILACA et Davi NACHTIGALL LAZZAROTTO

Observations :
Il y a deux fichiers .pro, il faut ouvrir 2048_graph 
Il y quelques fonctionnalités qui n'ont pas été impleméntées :
 - On n'a pas eu le temps de faire les animations, puisque on aurait dû changer toute la structure de notre code pour le faire. La partie logique communique avec la partie graphique par moyen d'une QPROPERTY status, qui envoie juste les numéro et la couleur de chaque position du tableau. Pour implémenter les animations, il aurait fallu envoyer des objets correstondant à chaque bloc.

- On n'a pas eu le temps de permettre à l'utilisateur de choisir la taille du tableau. On a même crée une fenêtre de configurations qui était censée de donner l'utilisateur cette option. Pourtant, si l'utilisateur choisit effectivement une autre dimension, la partie logique crée un tableau avec cette dimension, mais on n'est pas arriver à effacer dans la partie graphique le tableau précedant et créer un autre. Par contre, c'est possible de commencer avec un tableau de dimension différente de 4 dès le début, si on change le paramètre de la variable Game G(4) pour Game G(5) ou Game G(6) 
