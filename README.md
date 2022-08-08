# COMP313 Assignment 1 
## John Flynn

## Ghost of Death (Game)

[Gameplay video](https://www.youtube.com/watch?v=WB6w7ovocpk)

## Description

### Main mechanic
<!-- Stuff about the main action in the game -->
You play as a ghost in a big room. Move with WASD or Arrow keys.
- Over time, the room spawns enemies that walk toward you and shoot bullets at you.
- In your normal form, you will die if you touch enemies or bullets.
- If you press Space, you activate your ANGERED form, and move faster and destroy all enemies/bullets you touch.
- Your angered form only lasts for a second before needing to recharge, but killing an enemy resets the timer. This allows you to chain lots of kills to stay angry for longer.
- Increase your score by destroying enemies and bullets.

### Development difficulties
<!-- Getting the AI to want to take over the world was challenging as the return on investment is low. -->
The hardest part of the game to get working correctly was the Particle Systems, particularly the "blood" effect when that spews dark red circles when an enemy dies.
This was for a number of reasons:
- I used the (Legacy) Cascade particle editor to make it. I found the editor incredibly unintuitive, the documentation assumes you know what all the variable names/terms mean already, most online tutorials use a different version (Unreal 4) and don't explain how anything works, and a lot of the time the updates to the particle's Material aren't instantly reflected in the editor's viewport, which often made me think it wasn't working properly. I spent several hours learning how to use the "Velocity/Life" module through trial and error because I wanted the blood particles to slow down over time, but there were no tutorials available for it.
- A Particle System requires at least one Material. Because I had no starter content, I had to create the Material for blood from scratch. I thought this would be easy since I just wanted a simple opaque circle. I was wrong. This used another completely different editor. I had no experience with shaders, and all the documentation assumes you're an expert at them. Again, the online tutorials were very complex and skipped over basic explanations. Finally, every time I edited the Material, Unreal would freeze for several minutes to compile the shader. To create the circle Material, I basically had to find a tutorial for a complex Material with a circle in it, then dissect it so only the circle was left.
- This took me a very long time and serves no purpose other than appearance.

### Most interesting
<!-- The parts of the game that really shine and show off my programming ability -->
I think the most impressive part of the game's programming is how the "anger" mechanic manages so many different systems simultaneously:
- **The "Anger" Lifecycle.** The Ghost player has 3 states: Angry -> Cooling Down -> Calm (default). While Calm, if space is pressed the Ghost will become Angry. After a second, it starts Cooling Down, then when done it becomes Calm. These states are managed using a system of Timers and booleans.
- **Changing Flipbook.** When Calm/Cooling Down, the white ghost flipbook is used. When Angry, this is switched to the red ghost flipbook. Regardless of the flipbook, the Ghost's sprite continues its floating/bobbing animation (slowly bobs up and down using a cosine calculation) and faces the direction it is moving in (flips by inverting the relative scale X value).
- **Changing Movement Speed.** When Angry, movement speed is much higher. This is then reset to the default when Calm/Cooling Down.
- **Activating the Fire Particle System.** The fire particle system is activated when Angry, but otherwise deactivated.
- **Animating the Anger Progress Bar at the bottom of the screen.** When Angry, the progress bar turns red and drains with the remaining anger duration. When Cooling Down, it turns white and refills over the cooldown duration. When Calm, it turns orange, indicating that the bar is full and the player can activate Anger form again. This uses a system of Timelines, and requires event dispatching from the Ghost to Level blueprint, then communication with the GameHUD blueprint.
- **Changing Ghost interactions with Enemies/Bullets.** When Angry, Enemies and Bullets are destroyed when touched. Otherwise, the Ghost is destroyed instead.
- **Anger is reset when an enemy is killed.** Finally, to make everything 100x more complex, the anger Timer can be RESET at any time by killing an enemy while Angry. This required a lot of Timer and Timeline manipulation to get working correctly.

### Reflection on Learning
What was the most important this I learnt in the process.  One way to frame this is to look at things you struggled with and think about how you solved those and if that solution is **transferable** to similar situations.

Reflections can be at multiple levels.  Specific things that you learnt about the code, things you learnt about programming in the environment, things about programming in general, things about learning, or even things about how you value different aspects of your life. We expect you to cover the general programming and learning reflections based on specific examples but showing that you have generalised from those a more interesting lesson.

You need to edit this readme to discuss your project. .  If you are doing a technology then you need to change the header above.  Edit <your name> to be something like Simon McCallum

The assingment description is in [Assignment 1 markdown](assignment1.md) 
