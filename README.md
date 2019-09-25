# King's Trial
A text-based RPG. It has four levels, with each level having different enemies, items and special rooms.  

A player has the following stats:  
  - **Health points**: when it reaches 0 you lose.
  - **Attack**: the chance of successfully landing an attack.
  - **Strength**: the damage potential.
  - **Defense**: the damage absorption potential.
  - **Luck**: the chance of landing a critical strike; slightlty increases the chance of evading and landing an attack.
  - **Evasion**: the chance of evading an attack.
  - **Damage bonus**: increases your damage by a fixed amount.
  - **Damage reduction**: decreases the damage taken by a fixed amount.

Stats are increased by perks and equipment. Stats may also be raised temporarily by using a consumable item or an ability. Those persist for one enemy encounter.  

Special rooms:  
  - **Boss room**: the final room of a level, contains a strong foe that must be defeated to reach the next level.
  - **Treasure rooms**: there are two in each level. One contains an unique weapon and the other a powerful potion meant to be used before fighting the boss.
  - **Fountain room**: grants the player access to new perks that are unlocked by spending experience gained from defeating enemies.
  - **Rune room**: grants the player a new rune which has three unique abilities. Only one rune may be equipped. Using an ability costs charges. They are replenished by defeating enemies.
  - **Clue room**: the player is given a clue regarding the whereabouts of the secret room.
  - **Secret room**: a room which is hidden on the map. Contains an unique equippable item.
  
The player may use one of the following commands:
  - **go (or move) north/east/south/west**: moves the player's coordinate in specified direction. May begin an enemy encounter if it's a generic room.
  - **my stats**: outputs the player's stats.
  - **equipment**: outputs the items the player has equipped.
  - **perks**: outputs the perks the player has. 
  - **attune perk**: attempts to unlock the perk at the specified index.
  - **runes**: outputs the runes the player has.
  - **equip rune**: equips the rune at the specified index.
  - **inventory**: outputs the items the player has.
  - **use item**: uses the item at the specified index.
  - **drop item**: drops the item at the specified index.
  - **map**: outputs the user map.
  - **save**: saves the game to a file with the specified name.
  - **load**: loads the game from a file with the specified name.
  - **exit**: exits the game.
  
During combat the player may use one of the following commands:
  - **attack**: attempt to attack the enemy. This ends the player's turn.
  - **escape**: attempt to escape from the enemy. This ends the player's turn.
  - **my stats**: outputs the player's stats.
  - **enemy stats**: outputs the enemy's stats.
  - **equipment**: outputs the items the player has equipped.
  - **inventory**: outputs the items the player has.
  - **use item**: uses the item at the specified index. This ends the player's turn.
  - **use ability**: attempts to use the ability at the specified index. This ends the player's turn.
