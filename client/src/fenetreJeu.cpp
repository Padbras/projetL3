#include "fenetreJeu.hpp"
#include "gestionGrille.hpp"
#include "fenetreWin.hpp"
#include "fenetreLoose.hpp"

using namespace sf;
using namespace std;

// return 1 si gagné, -1 si perdu

int fenetreJeu(Player *player, TcpSocket *mySocket){

  ////////////////// creation et init de la fenetre //////////////////
  cout << "mon pseudo : " << player->getMyPseudo() << endl;
  cout << "pseudo adv : " << player->getPseudoOpp() << endl;
  
  //string affPseudo = "Peaceful Shadow Online : "
  //strcat(
  
  RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : La Bataille ",Style::Titlebar);
  window.setPosition(Vector2i(10, 10));


  ////////////////// creation et init des variables //////////////////

  int cpt = 0;
  int valide = 0;
  Grille tmp;
  int x1 , x2 , x3, x4, x5, y1, y2, y3, y4, y5;
  x1 = x2 = x3 = x4 = x5 = y1 = y2 = y3 = y4 = y5 =0;
  Event event;


  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/jeu.png")){
  }
  Font main_font;
  main_font.loadFromFile("../client/fonts/main_font.ttf");
  
  RectangleShape boutonValide(Vector2f(300, 60));
  boutonValide.setPosition(348,670);
  boutonValide.setFillColor(Color(0, 0, 0, 160));

  RectangleShape fenetreGrise(Vector2f(1000, 800));
  fenetreGrise.setPosition(0,0);


  //////////// creation des textes, sprites et textures //////////////
			
  Sprite fondEcran_spr(fondEcran_tex);
  
  Text myPseudo_txt;
 myPseudo_txt.setFont(main_font);
     myPseudo_txt.setCharacterSize(60);	
    myPseudo_txt.setPosition(180,115);
    myPseudo_txt.setString(player->getMyPseudo());
	myPseudo_txt.setColor(Color(255,255,255));
	
  Text pseudoOpp_txt;
 pseudoOpp_txt.setFont(main_font);
     pseudoOpp_txt.setCharacterSize(60);	
    pseudoOpp_txt.setPosition(645,115);
    pseudoOpp_txt.setString(player->getPseudoOpp());
	pseudoOpp_txt.setColor(Color(255,255,255));
	
	
  //////////// affichage de la fenetre ///////////////////////////////

  Packet	whoTurn;
  Packet	grille;
  bool		myTurn;
  int tour = 0; 
  
  whoTurn.clear();
  whoTurn = receivePacket(mySocket);
  whoTurn >> myTurn;
  std::cout << "Mon bool myTurn:" << myTurn << std::endl;

  if(myTurn)
    tour = -1;

  
  while (window.isOpen())
    {      
      if (cpt > 0)
		boutonValide.setFillColor(Color(0, 0, 0, 0));

      if (myTurn == false)
	{
	  fenetreGrise.setFillColor(Color(0, 0, 0, 160));
	  std::cout << "myturn false" << std::endl; 
	  cpt = 0;

	    window.clear(Color::White); 	
	      
      window.draw(fondEcran_spr);
      window.draw(boutonValide);

      for (int j = 0; j < 10; j++)
      	for (int i = 0; i < 10; i++)
      	  {
      	    player->getMyModifGrille()->setPosCase(i,j,retGrGauchX(i), retGrGauchY(j));
			tmp._grille[i][j]._case_rect = player->getMyGrille().getRect(i,j);
			window.draw(tmp._grille[i][j]._case_rect);
      	  }
      for (int j = 0; j < 10; j++)
      	for (int i = 0; i < 10; i++)
      	  {
			player->getModifGrilleOpp()->setPosCase(i,j,retGrDroitX(i), retGrDroitY(j));
      	    tmp._grille[i][j]._case_rect = player->getGrilleOpp().getRect(i,j);
      	    window.draw(tmp._grille[i][j]._case_rect);	    
      	  }
    window.draw(myPseudo_txt);
    window.draw(pseudoOpp_txt);
    window.draw(fenetreGrise);
      

      window.display();
      std::cout << "f attend myGrille"<< std::endl;
	player->initMyGrille(receiveGrille(mySocket));
      std::cout << "f attend Grilleopp"<< std::endl;
	player->setGrilleOpp(receiveGrille(mySocket));
	  whoTurn.clear();
	        std::cout << "f attend myturn"<< std::endl;
	  whoTurn = receivePacket(mySocket);
	  whoTurn >> myTurn;
	        std::cout << "f myturn : "<< myTurn << std::endl;
	  
	}
      //////////// gestion de la boucle d'evenements///////////////////////
      
      if (myTurn == true)
	{
	//	std::cout << "on rentre dans mon tour" << std::endl;
	  fenetreGrise.setFillColor(Color(0, 0, 0, 0));
	  while (window.pollEvent(event))
	    {
	      switch (event.type)
		{				
	      case Event::MouseButtonPressed :
	       // gestion de click dans la grille de tir
		if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
			event.mouseButton.y < 600 && event.mouseButton.y > 200)
			{	
			cpt = 0;
		  x1 = ptRetourX(event.mouseButton.x);
		  y1 = ptRetourY(event.mouseButton.y);
		        std::cout << "x "<< x1 << "y " << y1<< std::endl;
		  player->getModifGrilleOpp()->setColorCase(x1,y1,128,128,128,128);
		  cpt++;				
		}
					
		//gestion du click sur le bouton valider
		if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
			event.mouseButton.y < 730 && event.mouseButton.y > 670 && cpt == 1)
		  {
			  std::cout << "on clique sur le btn valider " << std::endl;
		    cpt = 0;
		    valide++;
		      tour = tour + 2;
		     if (player->getGrilleOpp().getTypeCase(x1, y1) == boat)
		      {
		        player->getModifGrilleOpp()->setTypeCase(x1, y1, touch);
		        player->getModifGrilleOpp()->setColorCase(x1, y1, 0, 255, 0, 128);
		     }
		     else if (player->getGrilleOpp().getTypeCase(x1, y1) == boat)
		      {
		        player->getModifGrilleOpp()->setTypeCase(x1, y1, miss);
		        player->getModifGrilleOpp()->setColorCase(x1, y1, 255, 0, 0, 128);
		     }
		    player->getGrilleOpp().afficherGrille();
		    
		    if (sendGrille(mySocket, player->getGrilleOpp()) == false)
		    {
				
			}
			if (sendGrille(mySocket, player->getMyGrille()) == false)
		    {
				
			}
		    whoTurn.clear();
		    whoTurn << tour;
		    if (sendPacket(&whoTurn, mySocket) == false)
		      {

		      }
		      if (valide > 0)
		      {
		    whoTurn.clear();
		    whoTurn = receivePacket(mySocket);
		    
		    whoTurn >> myTurn;
		    valide = 0;
		    }
	  }
		break;
						
	      default:
		break;
	      }
	    }
	   window.clear(Color::White); 	
	      
      window.draw(fondEcran_spr);
      window.draw(boutonValide);
      for (int j = 0; j < 10; j++)
      	for (int i = 0; i < 10; i++)
      	  {
	   
      	    player->getMyModifGrille()->setPosCase(i,j,retGrGauchX(i), retGrGauchY(j));
			tmp._grille[i][j]._case_rect = player->getMyGrille().getRect(i,j);
			window.draw(tmp._grille[i][j]._case_rect);
			
      	//    player->getMyModifGrille()->setPosCase(i,j,retGrGauchX(i), retGrGauchY(j));
      	  //  window.draw(player->getMyGrille().getRect(i,j));	    
      	  }
      for (int j = 0; j < 10; j++)
      	for (int i = 0; i < 10; i++)
      	  {
      	    player->getMyModifGrille()->setPosCase(i,j,retGrDroitX(i), retGrDroitY(j));
			tmp._grille[i][j]._case_rect = player->getGrilleOpp().getRect(i,j);
			window.draw(tmp._grille[i][j]._case_rect);
	   // player->getGrilleOpp().setPosCase(i,j,retGrDroitX(i), retGrDroitY(j));
      	 //   window.draw(player->getGrilleOpp().getRect(i,j));	    	    
      	  }
      window.draw(myPseudo_txt);
    window.draw(pseudoOpp_txt);
      window.draw(fenetreGrise); 

      window.display();
 

	}
    }
  return 0;
}


