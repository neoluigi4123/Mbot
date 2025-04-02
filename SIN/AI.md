# Informations globales sur le modele d'ia, sa banque de données, ses methode d'entrainement, etc

Voici le lien vers le [Lucid Chart](https://lucid.app/lucidchart/7f29a8b5-20e0-4dc4-a210-8b4b6dff8ea1/edit?invitationId=inv_ff67f26c-0aa7-416c-a5f0-be164a4885fd&page=0_0#) avec les diagrammes des possibles methodes utilisable pour faire des banques de données et entrainer le model afin d'utiliser plusieurs formats de reponses.

La camera sera positionée au bout de la pince. Cela permetra d'avoir le point de vue de la pince, et de la controller avec plus de facilité.

# Methode d'entrainement:
## Resources:
- https://github.com/modzy/hugging-face-raspberry-pi
## Faire un model a partir de zero, ou utiliser un model pre-entrainer?
- Si on fait appel a un entrainement a partir de zero, le model sera tres leger, relativement rapide, et aura une architecture propre a nous, pratique pour y avoir beaucoup de controle.
- Si on fait appel a un model pre-entrainer, et qu'on le [finetune](https://en.wikipedia.org/wiki/Fine-tuning_(deep_learning)) pour respecter notre banque de donnée, on se retrouvera avec un model plus capable, mais probablement plus lent, et qui ne respecte pas notre architecture de base, qui peux limiter le controle dans l'entrainement

Faire usage d'un model pre-entrainer est plus avantageux que d'utiliser un nouveau model en terme de qualité.
## Recherche effectuée sur les methodes utilisable possible sans faire appel a *Edge Impulse*

Pourquoi utiliser des librairie comme *TensorFlow* combiné avec *PyTorch* et ne pas utiliser Edge Impulse?
Voici un [papier de recherche](https://www.researchgate.net/publication/380122081_Edge_Impulse_vs_TensorFlow_A_Comparative_Analysis_of_TinyML_Platforms_for_Maize_Leaf_Disease_Identification) montrant les avantages et les desavantages d'utiliser *Edge Impulse*:

*Nos résultats démontrent qu'Edge Impulse a un léger avantage sur TensorFlow en termes de facilité d'utilisation, de fiabilité et d'empreinte mémoire, tandis que TensorFlow offre plus de flexibilité, d'options de personnalisation et une plus grande précision.*

**En gros: Edge Impulse est plus simple d'utilisation et gère des parametres precis important, tandit que TensorFlow permet d'avoir plus de controle et de précision pour un usage plus complexe (manuel)**

note: Edge Impulse fait deja usage de TensorFlow, en plus d'une multitude d'autre bibliotheque dans le meme domaine, permetant l'automatisation de taches, voici une liste des 8 plus *'importants'*:
- TFLite
- Edge Impulse
- PyTorch Mobile
- uTensor
- STM32Cube.AI
- NanoEdgeAIStudio
- NXPeIQ
- Microsoft's Embedded Learning Library

Cependant, notre architecture pourrait etre composer uniquement de ses trois la:
- TF
- PyTorch
- HFTransformers
Nous n'avons pas besoin d'outils tels que uTensor, Microsoft's Embedded Learning Library etc... Nous Avons egalement la possibilité d'utilisé des version plus *light* comme TFLite et PTMobile.
