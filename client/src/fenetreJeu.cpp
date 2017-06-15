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
  
  RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : La Bataille ",Style::Titlebar);
  window.setPosition(Vector2i(10, 10));

  ////////////////// creation et init des variables //////////////////

  int cpt = 0;
  int valide =0;
  Packet	whoTurn;
  Packet	grille;
  Packet    nbBoat;
  int tmpBoat;
  string myStr;
  bool		myTurn;
  bool onFire = false;
  int tour = 0; 
  Grille tmp;
  int x1 , y1, xOld, yOld, prochainPvr, sameTour, pvrStocke, cptAll, cptJap;
  x1 = y1 = xOld = yOld = -1;
  prochainPvr = pvrStocke = sameTour = cptAll = cptJap = 0;
  Event event;
  
 

  ////////////////// chargement des fonts et textures /////////////////

  Texture fondEcran_tex;
  if (!fondEcran_tex.loadFromFile("../client/img/jeu.png"))
    {
    }
  
  Font main_font;
  if(!main_font.loadFromFile("../client/fonts/main_font.ttf"))
    {
    }
  
  RectangleShape boutonValide(Vector2f(300, 60));
  boutonValide.setPosition(348,670);
  boutonValide.setFillColor(Color(0, 0, 0, 160));
  
  RectangleShape fenetreGrise(Vector2f(1000, 800));
  fenetreGrise.setPosition(0,0);
  fenetreGrise.setFillColor(Color(0, 0, 0, 200));
  
  CircleShape boutonPouvoir;
  boutonPouvoir.setRadius(65);
  boutonPouvoir.setPosition(100,635);
  boutonPouvoir.setFillColor(Color(0,0,0,160));

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
	
  Text attente_txt;
  attente_txt.setFont(main_font);
  attente_txt.setCharacterSize(60);	
  attente_txt.setPosition(260,20);
  attente_txt.setString("Votre adversaire joue son tour.");
  attente_txt.setColor(Color(255,255,255));
  
  Text cooldown_txt;
  cooldown_txt.setFont(main_font);
  cooldown_txt.setCharacterSize(15);	
  cooldown_txt.setPosition(260,764);
  cooldown_txt.setColor(Color(255,255,255));
	
  Text pouvoir_txt;
  pouvoir_txt.setFont(main_font);
  pouvoir_txt.setCharacterSize(60);	
  pouvoir_txt.setPosition(100,20);
  pouvoir_txt.setString("Cliquez dans la grille pour activer votre pouvoir");
  pouvoir_txt.setColor(Color(255,255,255));
  
  Text stackPvr_txt;
  stackPvr_txt.setFont(main_font);
  stackPvr_txt.setCharacterSize(60);	
  stackPvr_txt.setPosition(130,665);
  stackPvr_txt.setColor(Color(255,255,255));
		
  //////////// affichage de la fenetre ///////////////////////////////

  
  whoTurn.clear();
  whoTurn = receivePacket(mySocket);
  whoTurn >> myTurn;
  std::cout << "Mon bool myTurn:" << myTurn << std::endl;

  if(myTurn)
    tour = -1;
  
  while (window.isOpen())
    {      
      if (cpt > 0 && !onFire)
	boutonValide.setFillColor(Color(0, 0, 0, 0));

      if (myTurn == false)
	{
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
	  window.draw(attente_txt);
   
	  window.display();
	  
		// recevoir packet victoire/defaite -> myBoat
		nbBoat.clear();
		tmpBoat = 10;
		nbBoat = receivePacket(mySocket);
		nbBoat >> tmpBoat;
		player->setMyBoat(tmpBoat);
		if (player->getMyBoat() == 0)
		{
			return -1;
		}
	  // reception et conversion de ma grille
	  player->initMyGrille(receiveGrille(mySocket));
	  player->getMyGrille().convertGrilleGauche(player->getMyModifGrille());
	  // reception et conversion la grille adversaire
	  player->setGrilleOpp(receiveGrille(mySocket));
	  player->getGrilleOpp().convertGrilleDroit(player->getModifGrilleOpp());    
      
	  player->getGrilleOpp().afficherGrille();
		    
	  player->getMyGrille().afficherGrille();

	  whoTurn.clear();
	  std::cout << "f attend myturn"<< std::endl;
	  whoTurn = receivePacket(mySocket);
	  whoTurn >> myTurn;
	  std::cout << "f myturn : "<< myTurn << std::endl;
	  sameTour = 0;
	  
	}
      //////////// gestion de la boucle d'evenements///////////////////////
      
      if (myTurn == true)
	{
		
	  while (window.pollEvent(event))
	    {
	      switch (event.type)
		{				
		case Event::MouseButtonPressed :
		  // gestion de click dans la grille de tir sans pouvoir
		  if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
			event.mouseButton.y < 600 && event.mouseButton.y > 200 && !onFire)
		    {	
		      cpt = 0;
		      if (x1 != -1)
			{
			  xOld = x1;
			  yOld = y1;
			
			  // effacement des tirs precedents te non validés
		  if (player->getPaysId() != 2 && player->getPaysId() != 4
				&& player->getGrilleOpp().getTypeCase(xOld, yOld) != touch
				&& player->getGrilleOpp().getTypeCase(xOld, yOld) != miss)
				
			  player->getModifGrilleOpp()->setColorCase(xOld,yOld,128,128,128,0);
			}
		      x1 = ptRetourX(event.mouseButton.x);
		      y1 = ptRetourY(event.mouseButton.y);
		      std::cout << "x "<< x1 << "y " << y1<< std::endl;
		      player->getModifGrilleOpp()->setColorCase(x1,y1,128,128,128,128);
		      cpt++;				
		  
		    }
		    // gestion de click dans la grille de tir AVEC pouvoir
		  if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
			event.mouseButton.y < 600 && event.mouseButton.y > 200 && onFire)
		    {	
				std::cout << "IF TIR onfire : " << onFire << std::endl;
		      cpt = 0;
		      if (x1 != -1)
			{
			  xOld = x1;
			  yOld = y1;
			
			  // effacement des tirs precedents te non validés
			  if (player->getPaysId() != 2 && player->getPaysId() != 4
				&& player->getGrilleOpp().getTypeCase(xOld, yOld) != touch
				&& player->getGrilleOpp().getTypeCase(xOld, yOld) != miss)
				player->getModifGrilleOpp()->setColorCase(xOld,yOld,128,128,128,0);
			}
			
		      x1 = ptRetourX(event.mouseButton.x);
		      y1 = ptRetourY(event.mouseButton.y);
		      if (player->getPaysId() != 2 && player->getPaysId() != 4)
		      {
				player->callPvr(player->getPaysId(), x1, y1, player->getModifGrilleOpp());
				
		      onFire = false;
			}
		      else if (player->getPaysId() == 2)
		      {
				  
					player->callPvr(player->getPaysId(), x1, y1, player->getModifGrilleOpp());
				 cptAll++;
				 if (cptAll == 5)
					onFire = false;
			  }
			  else if (player->getPaysId() == 4)
			  {
				  
					player->callPvr(player->getPaysId(), x1, y1, player->getModifGrilleOpp());
				cptJap++;
				if (cptJap == 2)
					onFire = false;
			  }
		      
		      std::cout << "x "<< x1 << "y " << y1<< std::endl;
			
		  
		    }
		// gestion du click bouton pouvoir		
		  if(	event.mouseButton.x < 230 && event.mouseButton.x >100 && 
			event.mouseButton.y < 765 && event.mouseButton.y > 635 && (pvrStocke > 0 ||
			(player->getPaysId() == 5 && player->getMyBoat() != 17)))
		    {	
				if (player->getPaysId() != 5)
				{
				pvrStocke--;
				onFire = true;
			}
			else
			{
				pouvoirPirate(player->getMyModifGrille());
				pvrStocke--;
			}
		    }
				
					
		  //gestion du click sur le bouton valider
		  if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
			event.mouseButton.y < 730 && event.mouseButton.y > 670 && cpt == 1 && !onFire)
		    {
		      cpt = 0;
		      std::cout << "on clique sur le btn valider " << std::endl;
		      valide++;
		      tour = tour + 2;
		      if (player->getGrilleOpp().getTypeCase(x1, y1) == boat)
			{
			  player->getModifGrilleOpp()->setTypeCase(x1, y1, touch);
			  player->getModifGrilleOpp()->setColorCase(x1, y1, 0, 255, 0, 128);
			  player->suppboatOpp(1);
			}
		      else if (player->getGrilleOpp().getTypeCase(x1, y1) == mer)
			{
			  player->getModifGrilleOpp()->setTypeCase(x1, y1, miss);
			  player->getModifGrilleOpp()->setColorCase(x1, y1, 255, 0, 0, 128);
			}
		      std::cout << "ma grille | mon tour" << std::endl;
		      player->getGrilleOpp().afficherGrille();
		    
		      std::cout << "grille adv | mon tour" << std::endl;
		      player->getMyGrille().afficherGrille();
		      
		  
		  nbBoat.clear();
		nbBoat << player->getBoatOpp();
		
		 
		if (sendPacket(&nbBoat, mySocket) == false)
		{
			displayError("Failed to send packet");
		}
		      if (sendGrille(mySocket, player->getGrilleOpp()) == false)
			{
			displayError("Failed to send grille");
				
			}
			
		      if (sendGrille(mySocket, player->getMyGrille()) == false)
			{
			displayError("Failed to send grille");
				
			}
		      whoTurn.clear();
		      whoTurn << tour;
		      if (sendPacket(&whoTurn, mySocket) == false)
			{
			displayError("Failed to send packet");

			}
		      if (valide > 0)
			{
			  whoTurn.clear();
			  whoTurn = receivePacket(mySocket);
		    
			  whoTurn >> myTurn;

			  x1 = y1 = -1;
			  valide = 0;
			}
			if (player->getBoatOpp() == 0)
				return 1;
		    }
		  break;
						
		default:
		  break;
		}
	    }
	    
	    if (sameTour == 0)
	    {
			prochainPvr++;
			if (prochainPvr == player->getCooldown() && player->getPaysId() != 4)
				{
					pvrStocke++;
					prochainPvr = 0;
				}
			else if (player->getMyBoat() % 3 == 2 && player->getPaysId() == 4
						&& player->getMyBoat() != 17)
			{
				pvrStocke++;
				prochainPvr = 0;
			}
			std::cout << "1 :" << player->getMyBoat() % 3 << " 2 :" << player->getPaysId() << " 3 :" << player->getMyBoat() << std::endl;
			
		
		} 
		
		stringstream ss;
		ss << pvrStocke;
		myStr=ss.str();
		stackPvr_txt.setString(myStr);		
	/*	myStr=ss.str();		
		ss << prochainPvr;
		
		myStr=string(strcat("Nombre de tour avant votre prochain pouvoir : ", myStr));
		cooldown_txt.setString(myStr);*/
		
		if (pvrStocke == 0)
			boutonPouvoir.setFillColor(Color(0,0,0,160));
		else
			boutonPouvoir.setFillColor(Color(0,0,0,0));

	    
	  window.clear(Color::White); 	
	      
	  window.draw(fondEcran_spr);
	  window.draw(boutonValide);
	  if(onFire)
		 window.draw(pouvoir_txt);
	  window.draw(stackPvr_txt);
	  window.draw(cooldown_txt);
	  window.draw(boutonPouvoir);
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
		player->getMyModifGrille()->setPosCase(i,j,retGrDroitX(i), retGrDroitY(j));
		tmp._grille[i][j]._case_rect = player->getGrilleOpp().getRect(i,j);
		window.draw(tmp._grille[i][j]._case_rect);  	    
	      }
	  window.draw(myPseudo_txt);
	  window.draw(pseudoOpp_txt);

	  window.display();
 sameTour++;

	}
    }
  return 0;
}


