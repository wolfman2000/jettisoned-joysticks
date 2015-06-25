# Program Plan

This is a formal plan to ensure that a guideline of sorts is followed during the creation of this game.

## Question Data

It is best to view the sample `json` format below.

Keep in mind that any statement that says "relative path" or similar means relative to a parent package.

```json
[
  {
    "categoryName": "Category Name Here",
    "hiddenScore": 2,
    "isCategoryParent": false,
    "introTransitionPause": 5,
    "introGraphic": "Relative path to the graphic to show for this category. Can be empty.",
    "introSound": "Relative path to the intro sound played upon revealing this category. Can be empty.",
    "questionGraphic": "Relative path to a small graphic that shows in the corner/top during the actual question.",
    "questionMusic": "Relative path to the music that plays during the question. Can be empty.",
    "questionProdSuccess": "Was the player successful? (Or some other similar phrase)",
    "questionRightSound": "Relative path to the sound that plays if the player is right. Should not be empty.",
    "questionWrongSound": "Relative path to the sound that plays if the player is wrong. Should not be empty.",
    "questions": 
    [
      {
        "choice": "Default: could be a specific phrase if multiple.",
        "chosenQuestions":
        [
          {
            "priority": 0,
            "questionText": "Put text here.\nPlease use new lines\ncleanly: there are\nfour lines max.",
            "questionGotcha": "Additional text after\nthe question text.\nLine limit applies.",
            "audioClue": "Relative path to a tune to play on command to give a hint to the answer. Can be empty.",
            "pictureClue": "Relative path to a picture to show to give a hint to the answer. Can be empty.",
            "questionAnswer": "Put the answer here."
          }
        ]
      }
    ]
    
  },
  {
    "categoryName": "Category Name Here"
  }
]
```

Some clarifications on the sample above are as follows:

* It is assumed that categories are the root.
* For paths to images and song files, it can be assumed that there is a package directory that contains the images.
* Category names are required.
* Hidden scores are optional: it defaults to 1 otherwise.
* All images and sounds are optional, but it does liven up the game.
* `isCategoryParent` is tricky: if true, then the questions are determined by a choice made by the user. If false, there is only one choice to make.
 * TODO: See if there is a way to make it so that if `isCategoryParent` is false, the additional array is not required in the json file.
* Some categories are harder than others. `hiddenScore` can be set to award a higher internal score if gotten right. This could be used to break ties.
* `priority` determines the likelihood of the question showing up.

## Score Data

After each player is done, they are scored. A score entry consists of the following:

* The person's name.
* The number of questions correct.
* The hidden score based off of what categories of questions were gotten right.
* The date of when the player's game ended.

## States

### Turned Program On State

* The program loads preferences from a specific file if it exists. If the file does not exist, default preferences are used and a preference file is saved.
* Question data is loaded.
* Score data is loaded.
* The main menu is presented after all pre-loading is done.

### Main Menu State

* The top portion of the screen will contain a logo of the game. (Text can work at the start.)
* A menu of options is available.
 * If "Start" is chosen, the game begins.
 * If "Scores" is chosen, the scores will be displayed.
 * If "Exit" is chosen, the game ends.

### High Scores State

This screen presents the top scores of the current session.

Scores can be wiped out on this screen.

### Game Begins State

First, the player states their name, and the host puts it in. Upon doing that, a grid of questions is presented.

### Grid State

Arrow keys or the mouse can be used to select which grid space is wanted. The player has no knowledge of the category behind the grid space chosen.

The player's name and current score are shown in the top corner. The top player's name and current score are shown in the opposite top corner.

Once a question is chosen, that grid square is marked off and cannot be chosen for the rest of the game.

If the game must end, the explicit Exit space can be chosen (off grid). You will be taken back to the Main Menu State.

### Question State

If a category graphic is set, that image is rendered fully. If an intro sound is set, the sound plays at this time, with no looping.

If the intro transition pause is set, it will take that many seconds before it loads up the question.

If the category is considered a parent, the user must decide which pool of questions to go for. Otherwise, the one pool is chosen.

If a question graphic is set, the graphic is shown. If question music is set, that tune will play on loop until right or wrong.

The question text is shown. If there is an audio or picture clue, a button can be pressed to present that clue to the player. If there is a gotcha filled in, that text shows up after the player attempts to guess.

The player gives their answer (or perhaps tries to complete a challenge). If incorrect:

* The player's game is over.
* The player's score is saved.
* The question wrong sound is played.
* Upon pressing a key, go back to the Game Begins State.

If the player is correct, though:

* The player is still alive.
* The player's score (both public and internal) is increased.
* The question right sound is played.
* Upon pressing a key, go back to the Grid State.

### All Clear State

If, for some reason, all questions are answered correctly...

TODO: Actually determine that.
