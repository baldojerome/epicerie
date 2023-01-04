#include "Article.h"

#include <iostream>
#include <list>


//BALJ17058609 baldo jerome 
//POINT DE SITUATION 
//partie realise mais il y a quelques erreurs de mise en pages que je ne comprend pas. 

using namespace std;
//declaration des fonctions 
void ajouterArticle(list<Article>&epicerie, Article article);
void afficherFacture(list<Article>epicerie);

int main()
{

    list<Article>epicerie;
    
    Article mesArticles[] =
    {
        Article("Banane", 1, 12),
        Article("Patate", 2, 3),
        Article("Pomme", 3, 12),
        Article("Poulet", 10, 1),
        Article("Oeuf", 5, 2),
        Article("Cadeau", 30, 2),
        Article("Patate", 1, 50),
    };
    
    

    for(Article article : mesArticles)
    {
        ajouterArticle(epicerie, article);
    }
    
    afficherFacture(epicerie);

    return 0;
}
// fonction pour rajouter des articles dans un objet epicerie
void ajouterArticle(list<Article>& epicerie, Article article)
{ 
    //si list est vide alors push back
    if (epicerie.size() == 0)
    {
        epicerie.push_back(article);
    }
    else //sinon realiser une insertion selon une methode decroissante 
    {
        list<Article>::iterator iterateur = epicerie.begin();
        int i = 0;
        int rang = 0;
        int valeurComp = article.getMontant() * article.getQuantite();
            //algorithme pour  positionner l'article dans list 
            for(iterateur ; iterateur != epicerie.end(); ++iterateur)
            {
                
                if (valeurComp < (iterateur->getMontant()*iterateur->getQuantite()))
                {
                    rang++;
                }
            }
            
        list<Article>::iterator it = epicerie.begin();
        //pour positionner l'iterateur 
        advance(it, rang);
        //insertion selon position de l'iterateur
        epicerie.insert(it, article);
    }
}
//fonction pour l'affichage de list 
//utilise la surcharge de la classe article pour une sortie des articles 
void afficherFacture(list<Article> epicerie)
{
    int total = -1;
    cout << "  NOM \t\t" << "MONTANT " << "QUANTITE " << "SOUS-TOTAL" << endl;

    list<Article>::iterator it;
    for (it = epicerie.begin(); it != epicerie.end(); it++)
    {
        cout << *it  << endl;
        //incrementation du total qui sera afficher par la suite. 
        total = total + (it->getMontant()*it->getQuantite());
    }
    cout << "  TOTAL------------------------- " << total << endl;
}
