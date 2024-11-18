## Game Design for KnucleBones:


### Player Class:

#### Data:
 - name
 - score
 - dice_set: Array of Dice objects
 - player_stats

#### Actions:

- roll_dice(): Roll the dice for the player.
- get_score(): Retrieve the current score.
- update_score(points): Update the player’s score after each roll.
  
#### Relationships:

A Player HAS-A Dice (composition).
A Player IS-A participant in the game.

