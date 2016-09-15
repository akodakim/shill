/* 
 * File:   argument.h
 * Author: Abdelhakim Akodadi <akodadi.abdelhakim@gmail.com>
 * Brief: Command line options and arguments parser.
 *
 * Created on September 15, 2016, 7:40 AM
 */

#ifndef ARGUMENT_H
#define ARGUMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <argp.h>

    /* Program documentation. */
    static char doc[] =
            "\nInteract with people right form your terminal\n";

    /* A description of the arguments we accept. */
    static char args_doc[] = "";

    /* Supported options. */
    static struct argp_option options[] = {
        {"verbose", 'v', 0, 0, "Produce verbose output (disabled by default)", 0},
        {"config", 'c', "FILE", 0, "Set configuration file (default config.json)", 1},
        /*
            {0, 0, 0, 0, "The following options should be grouped together:", 1},
         */
        { 0}
    };

    /* Used by the main function to communicate with parse_opt. */
    struct arguments {
        int verbose;
        char *config;
    };
    
    /* Parse a single option. */
    error_t parse_opt(int key, char *arg, struct argp_state *state);
    
    /* Our argp parser. */
    static struct argp argp = {options, parse_opt, args_doc, doc, NULL, NULL, NULL};
    struct arguments arguments;


#ifdef __cplusplus
}
#endif

#endif /* ARGUMENT_H */
