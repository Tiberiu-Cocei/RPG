#include "AbilityList.h"

AbilityList::AbilityList() {}

Ability* AbilityList::get_ability(int index){
    switch(index) {
        //case 1-10: Rune of earth
        case 1 :
            return new Ability("Rock Volley", "Gathers a high number of rocks that are then launched toward the enemy.",
                               "Out of thin air a high numbers of rocks are created. Thrusting your arm forward, they are launched in the direction of your foe.",
                               false, false, 2, 1, 1.7f, 0, 0, 0, 0, 0);
        case 2 :
            return new Ability("Tectonic Slam", "Splits the earth in two under the enemy, then slams them between. Immobilizes the foe.",
                               "With a thundering crack, the earth below your foe splits in two then slams it between. \nThe enemy is stuck and unable to attack the next turn.",
                               false, true, 3, 1, 2.0f, 0, 0, 0, 0, 0);
        case 3 :
            return new Ability("Harden", "Creates a layer of earth surrounding your armor, temporarily increasing defenses and empowering future abilities.",
                               "Dirt and rocks come together, creating a hardened layer on your armor and empowering the rune.",
                               true, false, 2, 1, 0.0f, 0, 0, 7, 0, 0);

        //case 11-20: Rune of water
        case 11 :
            return new Ability("Healing wave", "Creates a layer of healing water on yourself, mending wounds.",
                               "Healing water appears on your body, healing you.",
                               true, false, 3, 2, 1.5f, 0, 0, 0, 0, 0);
        case 12 :
            return new Ability("Drown", "Floods your foe in water in an attempt to drown them. Immobilizes the foe.",
                               "An increasing amount of water appears out of thin air, covering your enemy entirely. \nYour foe falls to the ground, being unable to attack the next turn.",
                               false, true, 3, 2, 1.65f, 0, 0, 0, 0, 0);
        case 13 :
            return new Ability("Flow", "Your attacks become fluid like water, increasing their chance of striking the enemy.",
                               "Your arms feel much lighter and their movement fluid. The rune shines brighter, signaling an increase in power.",
                               true, false, 2, 2, 0.0f, 11, 0, 0, 7, 0);

        //case 21-30: Rune of air
        case 21 :
            return new Ability("Tornado", "Bends the air around your foe, making it swirl violently.",
                               "Your enemy is hit by a tornado of wind, leading to a high number of cuts to appear on their body.",
                               false, false, 2, 3, 1.9f, 0, 0, 0, 0, 0);
        case 22 :
            return new Ability("Air slice", "Strikes your enemy from afar with a sharp ripple of air and sends you flying backwards.",
                               "You strike directly in front of you, creating a ripple of air that is headed towards the enemy and launches you backwards. \nYour foe must close the distance, thus being unable to attack the next turn",
                               false, true, 3, 3, 1.5f, 0, 0, 0, 0, 0);
        case 23 :
            return new Ability("Blur", "Manipulates the air around you, making you seem blurred to the enemy and enhancing the rune.",
                               "The air around you becomes twisted, increasing your evasion and the power of the rune.",
                               true, false, 3, 3, 0.0f, 0, 0, 0, 0, 8);

        //case 31-40: Rune of fire
        case 31 :
            return new Ability("Explosion", "Unleashes a fiery explosion upon your foe, dealing heavy damage.",
                               "With a loud boom, your enemy is hit by a violent explosion.",
                               false, false, 4, 4, 3.0f, 0, 0, 0, 0, 0);
        case 32 :
            return new Ability("Ignite", "Ignites your foe on fire, forcing it to extinguish itself.",
                               "Your enemy is suddenly set on fire. They attempt to extinguish themselves in a panic, thus being unable to attack the next turn.",
                               false, true, 3, 4, 2.0f, 0, 0, 0, 0, 0);
        case 33 :
            return new Ability("Boiling blade", "Heats your weapon to its boiling point while maintaining its form and shape.",
                               "Your blade becomes extremely hot, its exterior gaining a look of molten magma and your rune shining brighter.",
                               true, false, 3, 4, 0.0f, 0, 9, 0, 0, 0);

        //case 101-110: First boss
        case 101 :
            return new Ability("Flesh flail", "", "From underground emerges an appendage that looks like its made out of flesh. Quickly after, it attempts to strike you before fading away.",
                               true, false, 0, 0, 1.3f, 0, 0, 0, 0, 0);
        case 102 :
            return new Ability("Armor strike", "", "Numerous small appendages emerge from underground and attempt break your armor. You manage to cut them down but parts of your armor fell to the ground.",
                               true, false, 0, 0, 0.0f, 0, 0, 4, 0, 0);

        //case 111-120: Second boss
        case 111 :
            return new Ability("Chemical burn", "", "A stream of chemicals appears out of nowhere and splashes in your direction.",
                               true, false, 0, 0, 1.5f, 0, 0, 0, 0, 0);
        case 112 :
            return new Ability("Glue splash", "", "Your foe launches an attack which you manage to block. However, from their blade shoots out a glue-like mixture which slows your movement.",
                               true, false, 0, 0, 0.0f, 4, 0, 0, 0, 5);

        //case 121-130: Third boss
        case 121 :
            return new Ability("Whirlwind", "", "Your foe grasps their weapon tightly and launches a spinning attack strengthened by their rune.",
                               true, false, 0, 0, 1.5f, 0, 0, 0, 0, 0);
        case 122 :
            return new Ability("Strength sap", "", "A magic circle appears beneath you and saps some of your strength in an instant.",
                               true, false, 0, 0, 0.0f, 0, 8, 0, 5, 0);

        //case 131-140: Fourth level enemies
        case 131 :
            return new Ability("Fireball", "", "A ball of fire appears mid-air and shoots in your direction.",
                               true, false, 0, 0, 1.3f, 0, 0, 0, 0, 0);
        case 132 :
            return new Ability("Lava splash", "", "The land cracks beneath your feet and lava splashes forth.",
                               true, false, 0, 0, 1.6f, 0, 0, 0, 0, 0);

        //case 141-150: Fourth boss
        case 141 :
            return new Ability("Elemental strike", "", "A flurry of elements surround the King's blade as he leaps in for an attack.",
                               true, false, 0, 0, 2.2f, 0, 0, 0, 0, 0);
        case 142 :
            return new Ability("Impending doom", "", "A dark magic circle appears beneath you. Immediately after, you feel part of your power fade.",
                               true, false, 0, 0, 0.0f, 7, 7, 7, 7, 7);

        default :
            return new Ability("ERROR_ABILITY", "ERROR_ABILITY", "ERROR_ABILITY", false, false, 0, 0, 0.0f, 0, 0, 0, 0, 0);
    }
}

AbilityList::~AbilityList() {}
