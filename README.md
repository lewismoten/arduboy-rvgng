# atom-video-game-name-generator package

![The Video Game Generator](https://raw.githubusercontent.com/lewismoten/arduboy-rvgng/master/assets/the-video-game-generator.png)

This is a port of [The Video Game Name Generator](http://videogamena.me) (VGNG). This sketch allows you to generate random video game names on an Arduboy. This is great for test data, data entry and laughs on the go. A few examples:

* Stoic Death Carnage
* Retro UFO Soldier
* Wild Graveyard Revolution
* Masters of the Karaoke - Gold Edition
* Advanced Fighter Ransom

Start generating names by pressing a button.

![The Video Game Generator on Arduboy](https://raw.githubusercontent.com/lewismoten/arduboy-rvgng/master/assets/arduboy-video-game-generator.gif)

## Buttons

* `UP`, `DOWN`, `LEFT`, `RIGHT`, `A` Generate and allow similar terms (e.g. Nighttime Night Nightmare)
* `B` Generate and don't allow similar terms (e.g. Nighttime Night Nightmare)

## Limitations
The Arduboy is limited with 32k flash, 2.5k ram. The sketch is setup to use the max of both within a few bytes within the max capacity. Notice that *last Words* list is cut off as the memory isn't available to use the entire list. Any changes to the script need to be optimized for the memory constraint.

The program appears to hang sometimes. Turn the Arduboy off and on again to reset.

## License

License / Authorization of use from the original authors (Edward Younskevicius)
website:

```
If you'd like to use the VGNG on your website, feel free! If you want to make
your own version (or make a better one for me ;) ), the wordlist is called
video_game_names.txt, and the syntax should be simple enough to figure out
(three wordlists separated by dashes, with dupe protection listed after the
"^" and separated by pipes "|".) I only ask that, if you copy the VGNG for
your site, please don't use it for any profit-generating purpose (charging
for it or selling ads), and include a link back to this site.
```

http://videogamena.me/about.html
