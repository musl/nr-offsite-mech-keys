### Keymapping to Scripts, Shell commands and other fun stuff!

First off, there are a variety of options to do this for OSX.

Most of this 'can' be accomplished through automator, applescripts, and OSX's hotkey keybinds. Although you are unlikely to have good success with that.

Reasons why:
- OSX has a bug with binding keys to modifiers, like CMD,SHIFT,CTRL...
- Using an automator service on a global keybind command needs to start the service, then run your command, this can cause massive delays in keypress to action
- It just doesn't work for some people/configurations, this is stated in a vairety of places, I found this to also be the case


What I would recommend:

[Karabiner](https://pqrs.org/osx/karabiner/index.html) - This is some free software for rebinding keys to other inputs & allowing shell commands etc.

My reason to choose this is primarily that it is **free**, and open source, check out the source [here](https://github.com/tekezo/Karabiner-Elements)

Using these fun keybinding scripts:
- Install Karabiner
- using a terminal or finder navigate to  `~/.config/karabiner/assets/complex_modifications` and place the Example_keypress_actions.json in that folder
- Open karabiner preferences
- Switch to "Complex Modifications" tab
- Click the plus button, and add one or more of the examples.

Gotchas that might be helpful:
- Karabiner needs to be allowed to manipulate the system (changing inputs etc), you may have to go to **settings** > **security/privacy** and allow the application to make changes.




