# BitWars
![banner image](/images/banner.jpg)

Banner image by: LENZ

LENZ's work can be found at:

[LENZ's Instagram](https://www.instagram.com/lenzartz/)

## Story
---

You are part of the resistence.

You must pilot your GRT-OE fighter and survive waves of enemy fighters sent by the Binpire.

The goal of the game is to last as long as you can and solve the problem in the top left of the screen to continue the game.

If you don't solve the problem correctly, or get hit by one of the enemy fighters it is a game over and you will have to start over from the beginning.

## How To Play
___

You must solve the binary operations problem in the top left of the screen, by shooting your lazer at the enemy fighter with the right bit for building the answer.
The answer is built from right to left and position matters for the answer to be correct.
00001 is not the same as 10000.

If you get the answer wrong, the game over screen will give you the correct answer.

<b> Operations </b>

- &: For each bit in the first operator and the corresponding bit in the second operator must both be 1.

10101 & 01101 = 00101

- \|: For each bit in the first operator and the corresponding bit in the second operator, one of them must be 1.

10101 \| 01101 = 11101

- ^: For each bit in the first operator and the corresponding bit in the second operator, one must be 1 and the other must be 0.

10101 ^ 01101 = 11000

Convert binary to base 10: Each position is 2^[i] where i is the position number. Position starts from the right at 0.

You take the number in the position (1/0) and times it by 2^[i].

11111 = 1 * 2^4 + 1 * 2^3 + 1 * 2^2 + 1 * 2^1 + 1 * 2^0 = 31

- <<: Shift each bit left in the first operator by the value of the second operator. This is easier by converting the second operator to a base 10 value. Zeros are inserted from the right.

00001 << 00010 (00001 << 2) = 00100

- >>: Shift each bit right in the first operator by the value of the second operator.This is easier by converting the second operator to a base 10 value. Zeros are inserted from the left.

00010 >> 00001 (00010 >> 1) = 00001

## Controls
---

The GRT-OE can move up and down, and fire a lazer with the A button.

Press A button on the title screen to start, and on the game over screen to get back to the title screen.

Pause/Unpause the game by hitting the Left button.

## Screen
---

Top left displays the problem you have to solve.

Top right displays your answer so far.

Bottom left displays the round number.

Bottom right displays if your lazer is ready to fire again.

## How to Download
---
### .arduboy
Using an Arduboy game uploader, upload the .arduboy file to your Arduboy.

### .hex
Using an Arduboy game uploader that supports .hex files, or any other tools that can upload .hex files to the Arduboy, upload the .hex file to your Arduboy.
 
### source
Rename file from BitWars-master to BitWars then upload to Arduboy using the Arduino IDE.

## Game License
---
[MIT](https://opensource.org/licenses/MIT)
