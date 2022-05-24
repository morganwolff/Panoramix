# Panoramix

## Context

The year is 50 BC. Gaul is entirely occupied by the Romans. Well, not entirely... One small village of <br>
indomitable Gauls still holds out against the invaders. And life is not easy for the Roman legionaries who <br>
garrison the fortified camps of Totorum, Aquarium, Laudanum and Compendium... <br>

In this village the druid prepares a cooking pot of magic potions. The villagers get a serving of potion and <br>
then procede to beat roman soldiers. When the pot is empty, the villager wakes up the druid and waits until
the druid has refilled the pot.<br>

## Project

The purpose of this project is to study examples of threads and mutex programming and the algorithmic <br>
difficulties that go with it.<br>

### Usage

```
USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```
- nb_villagers: indicates the number of villagers (must be >0); <br>
- pot_size: indicates the maximum number that can be contained in the cooking pot (must be >0); <br>
- nb_fights: indicates the maximum number of fights a villager will engage in (must be >0); <br>
- nb_refills: incicates the maximum number of time the druid will refill the pot (must be >0); <br>

### Rules

The program must follow these rules:

- You MUST make use of semaphores;<br>
- You MUST make use of mutexes;<br>
- Each villager (and the druid) MUST run in its own thread;<br>
- The cooking pot is full at the start of the program:<br>
- A villager’s thread must stop when all the fights have been done (and hopefully won);<br>
- The druid’s thread must stop when he has no ingredients left (aka: nb_refills) to refill the pot;<br>
- The program must stop gracefully when all the villager’s threads have stopped.<br>

## Compilation

All compilations are executed using `make`.

```
make
make all
make re
make clean
make fclean
```
## Examples

Threads run asynchronously, so the outputs will not always be exactly in the same order <br>
but it must always follow all the rules previously indicated.
```
> ./panoramix 3 5 3 1
Druid: I’m ready... but sleepy...
Villager 2: Going into battle!
Villager 1: Going into battle!
Villager 0: Going into battle!
Villager 2: I need a drink... I see 5 servings left.
Villager 0: I need a drink... I see 4 servings left.
Villager 0: Take that roman scum! Only 2 left.
Villager 1: I need a drink... I see 3 servings left.
Villager 2: Take that roman scum! Only 2 left.
Villager 1: Take that roman scum! Only 2 left.
Villager 0: I need a drink... I see 2 servings left.
Villager 0: Take that roman scum! Only 1 left.
Villager 2: I need a drink... I see 1 servings left.
Villager 1: I need a drink... I see 0 servings left.
Villager 1: Hey Pano wake up! We need more potion.
Druid: Ah! Yes, yes, I’m awake! Working on it! Beware I can only make 0 more
refills after this one.
Druid: I’m out of viscum. I’m going back to... zZz
Villager 1: Take that roman scum! Only 1 left.
Villager 2: Take that roman scum! Only 1 left.
Villager 0: I need a drink... I see 4 servings left.
Villager 1: I need a drink... I see 3 servings left.
Villager 0: Take that roman scum! Only 0 left.
Villager 2: I need a drink... I see 2 servings left.
Villager 1: Take that roman scum! Only 0 left.
Villager 2: Take that roman scum! Only 0 left.
Villager 0: I’m going to sleep now.
Villager 1: I’m going to sleep now.
Villager 2: I’m going to sleep now.
```