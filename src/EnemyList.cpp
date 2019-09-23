#include "EnemyList.h"

EnemyList::EnemyList() {
    consumableItemList = new ConsumableItemList();
    equipableItemList = new EquipableItemList();
}

Enemy* EnemyList::get_enemy(int index) {
    EnemyStats* enemyStats;
    std::vector<ConsumableItem*> consumableDrops;
    std::vector<EquipableItem*> equipableDrops;
    switch(index) {
        //1-10: first level
        case 1 :
            enemyStats = new EnemyStats(30, 15, 29, 11, 17);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(102));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(71));
            equipableDrops.push_back(equipableItemList->get_equipable_item(2));
            equipableDrops.push_back(equipableItemList->get_equipable_item(152));
            return new Enemy(enemyStats, "Goblin", "You notice something green hide between the rocks. \nYou realize that it's a goblin and prepare for battle!",
                             "The goblin falls down, dying before hitting the ground.", consumableDrops, equipableDrops, 17, 10);
        case 2 :
            enemyStats = new EnemyStats(25, 18, 32, 5, 28);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(71));
            equipableDrops.push_back(equipableItemList->get_equipable_item(152));
            equipableDrops.push_back(equipableItemList->get_equipable_item(202));
            return new Enemy(enemyStats, "Skeleton", "From the darkness of the cave something leaps towards you. \nYou realize that it's a skeleton, something that should not be capable of standing let alone fighting. \nYou prepare yourself for battle!",
                             "The bones that form the skeleton break and fall to the ground.", consumableDrops, equipableDrops, 18, 10);
        case 3 :
            enemyStats = new EnemyStats(45, 10, 36, 14, 11);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(101));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            equipableDrops.push_back(equipableItemList->get_equipable_item(102));
            equipableDrops.push_back(equipableItemList->get_equipable_item(252));
            return new Enemy(enemyStats, "Giant Rat", "You hear loud squeaking noises come from somewhere near you. You prepare yourself for battle. \nMoments later, a giant rat jumps in front of you!",
                             "The giant rat falls over, dying shortly after.", consumableDrops, equipableDrops, 21, 20);
        case 4 :
            enemyStats = new EnemyStats(95, 23, 43, 23, 18);
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(104));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            equipableDrops.push_back(equipableItemList->get_equipable_item(52));
            equipableDrops.push_back(equipableItemList->get_equipable_item(302));
            return new Enemy(enemyStats, "Hobgoblin", "You see a weakly goblin trip on a rock and fall to the ground. \nIt turns around whimpering and pleading, to your confusion. \nThen you see the reason: a Hobgoblin towering above it. It raises its weapon to kill the goblin when it notices you. \nThe goblin escapes, and the hobgoblin charges towards you. You prepare for combat!",
                             "The hobgoblin falls with a loud thud, never to get up again.", consumableDrops, equipableDrops, 26, 35);
        case 5 :
            enemyStats = new EnemyStats(250, 32, 49, 27, 17);
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            equipableDrops.push_back(equipableItemList->get_equipable_item(302));
            equipableDrops.push_back(equipableItemList->get_equipable_item(302));
            return new Enemy(enemyStats, "Mass of flesh", "You're hit by a strong scent of rotting flesh. \nBefore you find the source of the odor an appendage narrowly misses you and loudly hits the floor. \nThat's when you see it: a massive mass of flesh, contracting and moving unnaturally. You prepare for battle!",
                             "The mass of flesh dissolves into a puddle of bones and blood.", consumableDrops, equipableDrops, 37, 500);

        //11-20: second level
        case 11 :
            enemyStats = new EnemyStats(50, 31, 39, 31, 27);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(102));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(72));
            equipableDrops.push_back(equipableItemList->get_equipable_item(3));
            equipableDrops.push_back(equipableItemList->get_equipable_item(153));
            return new Enemy(enemyStats, "Abomination", "You see something run towards you. It has many limbs and its flesh is mutated. \nYou prepare for battle!",
                             "The abomination falls down and starts convulsing. You put it out of its misery with your weapon.", consumableDrops, equipableDrops, 26, 50);
        case 12 :
            enemyStats = new EnemyStats(70, 39, 36, 25, 38);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(72));
            equipableDrops.push_back(equipableItemList->get_equipable_item(153));
            equipableDrops.push_back(equipableItemList->get_equipable_item(203));
            return new Enemy(enemyStats, "Man-spider", "Loud chewing noises can be heard from somewhere close to you. \nYou get closer to investigate, and find a man with six hands, using them to stand. \nIt twists its head towards you, pausing its feast. You prepare for combat!",
                             "With its limbs cut off, the man-spider falls down, bleeding out.", consumableDrops, equipableDrops, 30, 50);
        case 13 :
            enemyStats = new EnemyStats(90, 38, 45, 33, 46);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            equipableDrops.push_back(equipableItemList->get_equipable_item(103));
            equipableDrops.push_back(equipableItemList->get_equipable_item(253));
            return new Enemy(enemyStats, "Chimera", "A creature jumps down from one of the openings in the cave above, landing meters in front of you. \nIt looks as if many beasts were merged into one: a chimera. You prepare for combat!",
                             "The chimera falls apart into a puddle of flesh and bones.", consumableDrops, equipableDrops, 33, 75);
        case 14 :
            enemyStats = new EnemyStats(110, 51, 55, 41, 20);
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(104));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            equipableDrops.push_back(equipableItemList->get_equipable_item(53));
            equipableDrops.push_back(equipableItemList->get_equipable_item(303));
            return new Enemy(enemyStats, "Giant Mutant", "You hear something charge towards you. You roll to the side and avoid the attack. \nYou quickly get up and see a giant humanoid being, with limbs that seem to be fused together from many different beings. \nYou prepare for battle!",
                             "The giant mutant falls down, never to get up again.", consumableDrops, equipableDrops, 44, 100);
        case 15 :
            enemyStats = new EnemyStats(520, 63, 67, 51, 46);
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            equipableDrops.push_back(equipableItemList->get_equipable_item(303));
            equipableDrops.push_back(equipableItemList->get_equipable_item(303));
            return new Enemy(enemyStats, "Mad scientist", "\"So you're the one who has been killing my creations. Beautiful, weren't they? Until you killed them, that is.\" \n\"It's alright, I can start over again. And I shall begin with you!\" \nOnce the scientist finished his sentence, he started to convulse aggressively. With each twist, his body mutated and grew in size.",
                             "\"I was.. beautiful. You could have been too..\" The scientist finally succumbs to his wounds, the way forward now open.", consumableDrops, equipableDrops, 97, 1500);

        //21-30: third level
        case 21 :
            enemyStats = new EnemyStats(75, 62, 64, 47, 35);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(102));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(73));
            equipableDrops.push_back(equipableItemList->get_equipable_item(4));
            equipableDrops.push_back(equipableItemList->get_equipable_item(154));
            return new Enemy(enemyStats, "Spriggan", "A bright light suddenly appears from between the trees: a Spriggan has manifested itself!",
                             "The Spriggan turns to dust and a gust of wind sweeps it away.", consumableDrops, equipableDrops, 45, 200);
        case 22 :
            enemyStats = new EnemyStats(80, 51, 67, 49, 25);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(101));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(73));
            equipableDrops.push_back(equipableItemList->get_equipable_item(154));
            equipableDrops.push_back(equipableItemList->get_equipable_item(204));
            return new Enemy(enemyStats, "Giant boar", "You hear shuffling between the bushes. Suddenly, a giant boar comes out, charging towards you!",
                             "The boar falls to the ground with a loud thud.", consumableDrops, equipableDrops, 45, 200);
        case 23 :
            enemyStats = new EnemyStats(110, 72, 73, 52, 37);
            consumableDrops.push_back(consumableItemList->get_consumable_item(105));
            consumableDrops.push_back(consumableItemList->get_consumable_item(106));
            consumableDrops.push_back(consumableItemList->get_consumable_item(3));
            consumableDrops.push_back(consumableItemList->get_consumable_item(63));
            equipableDrops.push_back(equipableItemList->get_equipable_item(104));
            equipableDrops.push_back(equipableItemList->get_equipable_item(254));
            return new Enemy(enemyStats, "Dire bear", "A dire bear cuts your way. You try to back down without attracting its attention, but do so unsuccessfully.",
                             "The dire bear falls on its side, unable to get up. You finish it off.", consumableDrops, equipableDrops, 53, 350);
        case 24 :
            enemyStats = new EnemyStats(150, 65, 78, 58, 49);
            consumableDrops.push_back(consumableItemList->get_consumable_item(105));
            consumableDrops.push_back(consumableItemList->get_consumable_item(106));
            consumableDrops.push_back(consumableItemList->get_consumable_item(3));
            consumableDrops.push_back(consumableItemList->get_consumable_item(63));
            equipableDrops.push_back(equipableItemList->get_equipable_item(54));
            equipableDrops.push_back(equipableItemList->get_equipable_item(304));
            return new Enemy(enemyStats, "Treant", "The trees start to creak loudly nearby. You expect a huge enemy to come out to fight you. What you did not expect, however, was a living tree!",
                             "The treant falls over. You get out of its way to avoid being crushed.", consumableDrops, equipableDrops, 82, 500);
        case 25 :
            enemyStats = new EnemyStats(950, 92, 89, 72, 68);
            consumableDrops.push_back(consumableItemList->get_consumable_item(63));
            consumableDrops.push_back(consumableItemList->get_consumable_item(63));
            consumableDrops.push_back(consumableItemList->get_consumable_item(63));
            consumableDrops.push_back(consumableItemList->get_consumable_item(63));
            equipableDrops.push_back(equipableItemList->get_equipable_item(304));
            equipableDrops.push_back(equipableItemList->get_equipable_item(304));
            return new Enemy(enemyStats, "Minotaur", "\"Oh? A challenger? It has been such a long time since anyone has gotten this far.\" \nYou are taken aback by their words and ask: \"What do you mean? Hasn't everyone completed the trial?\" \nAs you finish your question, the minotaur starts to laugh. \"I see they're still keeping up the charade if you truly think that.\" \n\"I apologize, but I cannot tell you the truth. All that you need to know is that I must be defeated if you wish to continue.\" \nAs it doesn't seem you'll be getting any further response, you prepare for battle!",
                             "\"Well.. done..\" said the Minotaur with its last breath, dying shortly afterwards.", consumableDrops, equipableDrops, 165, 6500);

        //31-40: fourth level
        case 31 :
            enemyStats = new EnemyStats(135, 79, 79, 74, 75);
            consumableDrops.push_back(consumableItemList->get_consumable_item(106));
            consumableDrops.push_back(consumableItemList->get_consumable_item(3));
            consumableDrops.push_back(consumableItemList->get_consumable_item(4));
            consumableDrops.push_back(consumableItemList->get_consumable_item(74));
            equipableDrops.push_back(equipableItemList->get_equipable_item(5));
            equipableDrops.push_back(equipableItemList->get_equipable_item(155));
            return new Enemy(enemyStats, "Imp", "From the sky suddenly dives a reddish figure. You avoid its attack and prepare for battle!",
                             "The imp's body turns to ashes.", consumableDrops, equipableDrops, 76, 500);
        case 32 :
            enemyStats = new EnemyStats(163, 73, 81, 76, 82);
            consumableDrops.push_back(consumableItemList->get_consumable_item(106));
            consumableDrops.push_back(consumableItemList->get_consumable_item(3));
            consumableDrops.push_back(consumableItemList->get_consumable_item(4));
            consumableDrops.push_back(consumableItemList->get_consumable_item(74));
            equipableDrops.push_back(equipableItemList->get_equipable_item(155));
            equipableDrops.push_back(equipableItemList->get_equipable_item(205));
            return new Enemy(enemyStats, "Hellhound", "You hear something charge towards you. You manage to dodge in time and then prepare for battle!",
                             "The hellhound falls over and dies shortly after.", consumableDrops, equipableDrops, 80, 500);
        case 33 :
            enemyStats = new EnemyStats(208, 89, 87, 89, 77);
            consumableDrops.push_back(consumableItemList->get_consumable_item(106));
            consumableDrops.push_back(consumableItemList->get_consumable_item(4));
            consumableDrops.push_back(consumableItemList->get_consumable_item(5));
            consumableDrops.push_back(consumableItemList->get_consumable_item(64));
            equipableDrops.push_back(equipableItemList->get_equipable_item(105));
            equipableDrops.push_back(equipableItemList->get_equipable_item(255));
            return new Enemy(enemyStats, "Magma Golem", "Lava suddenly bursts in front of you. Rocks from around the eruption levitate and form a humanoid shape.",
                             "The rocks come undone and fall lifeless to the ground.", consumableDrops, equipableDrops, 89, 750);
        case 34 :
            enemyStats = new EnemyStats(305, 94, 95, 92, 90);
            consumableDrops.push_back(consumableItemList->get_consumable_item(4));
            consumableDrops.push_back(consumableItemList->get_consumable_item(5));
            consumableDrops.push_back(consumableItemList->get_consumable_item(5));
            consumableDrops.push_back(consumableItemList->get_consumable_item(64));
            equipableDrops.push_back(equipableItemList->get_equipable_item(55));
            equipableDrops.push_back(equipableItemList->get_equipable_item(305));
            return new Enemy(enemyStats, "Royal Guard", "A soldier with armor that you recognize as being of the royal army challenges you to a duel!",
                             "The guard kneels in defeat, dropping their weapon and congratulating you on your victory. They would speak no further.", consumableDrops, equipableDrops, 104, 1000);
        case 35 :
            enemyStats = new EnemyStats(1350, 107, 119, 110, 105);
            consumableDrops.push_back(consumableItemList->get_consumable_item(64));
            consumableDrops.push_back(consumableItemList->get_consumable_item(64));
            consumableDrops.push_back(consumableItemList->get_consumable_item(64));
            consumableDrops.push_back(consumableItemList->get_consumable_item(64));
            equipableDrops.push_back(equipableItemList->get_equipable_item(305));
            equipableDrops.push_back(equipableItemList->get_equipable_item(305));
            return new Enemy(enemyStats, "King", "\"I must congratulate you for reaching the end of the trial. It has been years since anyone has gotten this far.\" \n\"If what you say is true, what exactly happened to the others?\" you ask the King, confused. \n\"They all perished, the King responds. There was one survivor however, until you put them out of their misery that is, in the cave depths.\" \n\"That cannot be true. Everyone returned alive and well.. didn't they?\" you ask in disbelief. \n\"Not quite. Those who went through the trial and failed had been replaced by a doppler. \nA being indistinguishable from a human, created by a powerful rune using a memory imprint of the fallen subject.\" \n\"Why? you ask, distraught\" \n\"Because I could not allow word to spread about the trial. Its purpose is to choose the next King. \nThat person must be able to overcome the trial without any prior knowledge. \nEven runes that can manipulate the mind are ineffective in this regard. \nDeath or never leaving this place for those who fail are the only ways it can happen.\" \nSilence falls as you do not know what to say. It is broken shortly, however. \n\"I believe it is time to end this. Defeat me and you shall take my place. Lose and you shall die.\"",
                             "\"Congratulations, you have completed the trial and proven your worth.\" With a bright light, his wounds heal rapidly. \nAs the king stands up once more, he puts away his weapon. \n\"You shall begin your formal training in order to take my place, and I shall soon finally rest. \n\"It is a heavy burden that I entrust to you, but I am sure you will do better than me.\"", consumableDrops, equipableDrops, 236, 15000);

        default :
            enemyStats = new EnemyStats(100, 100, 100, 100, 100);
            consumableDrops.push_back(consumableItemList->get_consumable_item(0));
            consumableDrops.push_back(consumableItemList->get_consumable_item(0));
            consumableDrops.push_back(consumableItemList->get_consumable_item(0));
            consumableDrops.push_back(consumableItemList->get_consumable_item(0));
            equipableDrops.push_back(equipableItemList->get_equipable_item(0));
            equipableDrops.push_back(equipableItemList->get_equipable_item(0));
            return new Enemy(enemyStats, "ERROR_ENEMY", "ERROR_ENEMY",
                             "ERROR_ENEMY", consumableDrops, equipableDrops, 0, 0);
    }
}

EnemyList::~EnemyList() {}
