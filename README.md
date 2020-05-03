# 2D-ENGINE
Engine for devloping 2d games in sdl/glew. 

## Current Demo Setup
A simple Controlable polygon is implemented, controls are WASD for movement and QE for rotation. in addition UP,Down zoom the camera and LEFT,Right rotate the camera. 

## API
Components:
game object hold components from components.h according to what functionality they need. each component may have methods which need to be called once per tick ie update,render. these should be called in a respective update/render
function of the parent object. these in turn are called by gameManager during that part of the tick cycle

ie) player has compoent RigidBody

during gameManager.update:

    this->player.update()
    //other stuff

in player.update():
    this->rigidBody.update()
    //other stuff

similar is true for render and soforth.

controls and events:
any game object which is influenced by events must have a .events() method which takes in SDL_Event* event, it should also be placed in the event loop in gameManager.events() and passed the SDL_Event*. 

likewise for the state of the keyboard, if your object is influenced by which keys are currently pressed, it must have a .keys() method which takes in const Uint8* keys. it should also be placed in gameManager.events() after the event loop. 



## Adding assets
asset storage and addition is done by assets.h and its respective class, for each type of asset in the game there
will be a loader which takes in the component onto which the asset is to be loaded, and the asset to be loaded 
(with is a member of the assets class). the loader is called in the game objects init method

currently the only asset type is a complex vector which is loaded onto the component polygon, these can be created
using point-input-tool and simply pasted as a memeber in assets.cpp as done with the player asset.

## Future Devlopment
interactions between game objects is the next system that must be made. this will be done by having a .interaction() 
method on gameManager which calles .interaction() for game objects which implement that behavior. each game object
will be passed whatever it needs to preform its itnereactions, hence this step wont be as uniform as the update and render steps

going further, to implement many objects of the same type, managers must be put in place (ie bullet manager) which
use object pooling and handel the interactions, update and render methods of the objects they manage.

collision is somthing which could either be done through the interaction system, or through its own bespoke system using somthing like collision layers 