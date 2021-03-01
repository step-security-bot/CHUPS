# CHUPS
Check UP Status

## But du projet :
Réaliser un programme avec interface CLI capable de dire si un hôte est 'up' (disponible) ou pas sur le réseau.

Deux techniques pour vérifier ceci seront exploitées :

1. Un scan SYN/ACK qui essayera de se connecter à un hôte sur un port spécifié
2. Un ping (paquet ICMP) envoyé à l'hôte et le programme se chargera d'analyser la réponse afin de déterminer si l'hôte est disponible sur le réseau.

## Dev Rules
Les commentaires sont en Français.

Les noms de variables/fonctions/typedefs sont en camelCase et en Anglais.

La doc est en Français.