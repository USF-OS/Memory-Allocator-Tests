/**
 * @file
 *
 * Text-based UI functionality. These functions are primarily concerned with
 * interacting with the readline library.
 */

#ifndef _UI_H_
#define _UI_H_

void init_ui(void);
void destroy_ui(void);
char *read_command(void);
char *prompt_line1(void);
char *prompt_line2(void);
void set_last_status(int status);

#endif
