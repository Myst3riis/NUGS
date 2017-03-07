:
## N.U.G.S. est une intelligence artificielle ultra développée qui répond à toutes vos questions !

erreur(){
echo "T'as vu comment tu me parles ?"
echo "Je suis pas un robot, écris normalement !"
}

chepa(){
arr[0]="Je sais pas."
arr[1]="Arrete c'est dur."
rand=$[ $RANDOM % 2]
echo ${arr[$rand]}
#echo "NUMBER"
}

pascompri(){
arr[0]="J'ai pas compris."
arr[1]="Je crois qu'il faut que je dorme."
arr[2]="pfff... la flemme..."
arr[3]="Euh, je le sens pas..."
arr[4]="Je sais pas. Tu veux passer manger un burger ?"
arr[5]="Arrête de te moquer !"
arr[6]="Il est pas frais mon steak ?"
arr[7]="J'crois je suis un peu con en fait..."
arr[8]="Mais qu'est-ce que vous faites ??"
rand=$[ $RANDOM % 9]
echo ${arr[$rand]}
#echo "GLOBAL"
}

passur(){
echo "Je suis pas sur."
}

pourquoi(){
echo "Je sais pas, tu m'as gavé."
#echo "pourquoi"
}

bonjour(){
arr[0]="Euh... salut !"
arr[1]="Euh... bonjour..."
arr[2]="Euh... bonjour !"
arr[3]="Euh... salut..."
arr[4]="pfff... pas envie de parler..."
rand=$[ $RANDOM % 5]
echo ${arr[$rand]}
#echo "bonjour"
}

question(){
arr[0]="J'ai pas compris."
arr[1]="Euh, je sais pas trop..."
arr[2]="Je crois qu'il faut que je dorme."
arr[3]="Je sais pas. Tu m'embêtes, j'ai faim !"
arr[4]="Euh, je le sens pas..."
arr[5]="Plus ou moins..."
arr[6]="Comment tu sais ?"
arr[7]="Je sais pas. Tu veux passer manger un burger ?"
arr[8]="J'ai oublié."
arr[9]="Je sais pas, j'ai pas payé le mois de Février."
rand=$[ $RANDOM % 10]
echo ${arr[$rand]}
#echo "question"
}

non(){
arr[0]="Pff.. T'es pas cool."
arr[1]="Bon bah tant pis, je vais me coucher."
rand=$[ $RANDOM % 2]
echo ${arr[$rand]}
#echo "non"
}

oui(){
arr[0]="Cool !"
rand=$[ $RANDOM % 1]
echo ${arr[$rand]}
#echo "oui"
}

helpfct(){
echo "Demandez quelque chose à Nugs, et... bonne chance ! Vous pouvez :
- lui poser un calcl
- lui dire bonjour
- lui demander \"pourquoi\"."
}

str=
for i in "$@"; do
        str="$str$i"
done

#option="$1"
option="$str"
shift;
case "$option" in
[bB]onjour*) bonjour;;
[cC]oucou*) bonjour;;
[sS]alut*) bonjour;;
[hH]ey*) bonjour;;
[pP]ourquoi*) pourquoi;;
[oO]ui*) oui;;
[aA]vecplaisir*) oui;;
[nN]on*) non;;
[a-zA-Z.]*[?]) question;;
[a-zA-Z.]*) pascompri;;
--help) helpfct;;
[0-9]*) chepa;;
[\\\$\*\µ\:\!\&\#\^\%]*) erreur;;
esac
