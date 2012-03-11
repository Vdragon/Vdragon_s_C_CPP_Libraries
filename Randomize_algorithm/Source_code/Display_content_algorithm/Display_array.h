/*
 * Display_array.h
 *
 *  Created on: 2012/3/11
 *      Author: vdragon
 */

#ifndef DISPLAY_ARRAY_H_INCLUDED
  #define DISPLAY_ARRAY_H_INCLUDED
  void displayArrayInt(const int source[] , /*source_array*/
                        const unsigned source_size, /*array size*/
                        const unsigned item_field_width, /*field width of all items*/
                        const char delimit_character_sequence[], /*character sequence to apart 2 items*/
                        const unsigned items_per_line); /*how many items to show in one line*/

#endif /* DISPLAY_ARRAY_H_INCLUDED */
