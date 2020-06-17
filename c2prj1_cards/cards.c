#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2);
  assert(c.value<=VALUE_ACE);
  assert(c.suit>= SPADES);
  assert(c.suit<= CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r)
    {
    case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
    case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
    case FULL_HOUSE: return "FULL_HOUSE"; break;
    case FLUSH: return "FLUSH"; break;
    case STRAIGHT: return "STRAIGHT"; break;
    case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
    case TWO_PAIR: return "TWO_PAIR"; break;
    case NOTHING: return "NOTHING"; break;
    }
  return "";
}

char value_letter(card_t c) {
  char x;
  if(c.value>= 2 && c.value<=9)
    x= c.value+ '0';
  else
    switch(c.value)
      {
      case 10: x= '0'; break;
      case VALUE_JACK: x= 'J'; break;
      case VALUE_QUEEN: x= 'Q'; break;
      case VALUE_KING: x= 'K'; break;
      case VALUE_ACE: x= 'A'; break;
      }
  return 'x';
}


char suit_letter(card_t c) {
  char x;
  switch(c.suit)
    {
    case SPADES: x= 's'; break;
    case DIAMONDS: x= 'd'; break;
    case HEARTS: x= 'h'; break;
    case CLUBS: x='c'; break;
    }
  return 'x';
  
}

void print_card(card_t c) {
  char a= value_letter(c);
  char b= suit_letter(c);
  printf("%c%c", a,b);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let)
    {
    case '2': temp.value= 2; break;
    case '3': temp.value= 3; break;
    case '4': temp.value= 4; break;
    case '5': temp.value= 5; break;
    case '6': temp.value= 6; break;
    case '7': temp.value= 7; break;
    case '8': temp.value= 8; break;
    case '9': temp.value= 9; break;
    case '0': temp.value= 10; break;
    case 'J': temp.value= VALUE_JACK; break;
    case 'Q': temp.value= VALUE_QUEEN; break;
    case 'K': temp.value= VALUE_KING; break;
    case 'A': temp.value= VALUE_ACE; break;
    }
  switch(suit_let)
    {
    case 's': temp.suit= SPADES; break;
    case 'd': temp.suit= DIAMONDS; break;
    case 'h': temp.suit= HEARTS; break;
    case 'c': temp.suit= CLUBS; break;
    }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  switch(c/13)
    {
    case 0: temp.suit= SPADES; break;
    case 1: temp.suit= DIAMONDS; break;
    case 2: temp.suit= HEARTS; break;
    case 3: temp.suit= CLUBS; break;
    }
  switch(c%13){
  case 0: temp.value= 2; break;
  case 1: temp.value= 3; break;
  case 2: temp.value= 4; break;
  case 3: temp.value= 5; break;
  case 4: temp.value= 6; break;
  case 5: temp.value= 7; break;
  case 6: temp.value= 8; break;
  case 7: temp.value= 9; break;
  case 8: temp.value= 10; break;
  case 9: temp.value= VALUE_JACK; break;
  case 10: temp.value= VALUE_QUEEN; break;
  case 11: temp.value= VALUE_KING; break;
  case 12: temp.value= VALUE_ACE; break;
  }
  return temp;
}