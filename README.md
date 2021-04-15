![BUILD](https://github.com/unguest/CHUPS/actions/workflows/c-cpp.yml/badge.svg)

# CHUPS
Check UP Status

## But du projet :
Réaliser un programme avec interface CLI capable de dire si un hôte est 'up' (disponible) ou pas sur le réseau.

Deux techniques pour vérifier ceci seront exploitées :

1. Un scan utilisant le protocole PCT (Protocole de Contrôle de Transmissions*) qui essayera de se connecter à un hôte sur un port spécifié
2. Un ping (paquet ICMP) envoyé à l'hôte et le programme se chargera d'analyser la réponse afin de déterminer si l'hôte est disponible sur le réseau.

Les adresses IPV4 & IPV6 sont supportées.

Chaque type de scan (ICMP / SYNACK) sera codé dans un fichier portant le nom du scan.

## Comment l'utiliser ?

Tout d'abord, compilez le programme comme suit :

```bash
cmake .
make
```

Ensuite, lancez l'interface CLI de la manière suivante :

```bash
chmod 700 bin/CHUPS
./bin/chups
```

Une fois dans l'interface, ajoutez quelques hôtes avec l'option correspondante puis entrez dans le Watch Mode. Ce mode n'affiche rien à l'écran et rafraîchi les status et autres données des hôtes toutes les 2 secondes avant d'écrire le résultat dans des fichiers.

Ce mode est conçu pour fonctionner avec l'interface web qui relève les données toutes les 4 secondes.

Pour ce faire, démarrez l'interface web avec les commandes suivantes :

```bash
sudo apt install node npm # Seulement si vous n'avez pas encore ces paquets 
cd web
npm install
npm run-script run
```

Elle démarrera sur le port 8080 sauf si vous avez spécifié la variable d'environnement ```process.env.PORT``` au préalable. L'URL d'accès est donc `http://localhost:8080`

Les données temporaires sont strockées dans des fichiers en extension .lastest. Afin de tous les supprimer, un fichier ```purge.sh``` est inclut.

## Règles de développement

Les noms de variables/fonctions/typedefs sont en camelCase et en Anglais.

La doc et les commentaires _inline_ sont en Français.

Le projet utilise les sockets UNIX donc est uniquement compatible avec Mac OS X & les distributions linux.

## Logs de changements

### Version 0.1
- Support d'IPV4
- Scans TCP
- Interface web

### Version 0.2
- Support d'IPV6
- Scans ICMP
- Amélioration de la stabilité globale du programme
