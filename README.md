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
The parts of the game that really shine and show off my programming ability

### Reflection on Learning
What was the most important this I learnt in the process.  One way to frame this is to look at things you struggled with and think about how you solved those and if that solution is **transferable** to similar situations.

Reflections can be at multiple levels.  Specific things that you learnt about the code, things you learnt about programming in the environment, things about programming in general, things about learning, or even things about how you value different aspects of your life. We expect you to cover the general programming and learning reflections based on specific examples but showing that you have generalised from those a more interesting lesson.

You need to edit this readme to discuss your project. .  If you are doing a technology then you need to change the header above.  Edit <your name> to be something like Simon McCallum

The assingment description is in [Assignment 1 markdown](assignment1.md) 
