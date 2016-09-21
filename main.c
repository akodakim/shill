#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <jansson.h>
#include "argument/argument.h"
#include "configuration/configuration.h"
#include "command/command.h"

int main(int argc, char** argv) {
    /*
     * Default values.
     */
    arguments.verbose = 0;
    arguments.config = "config.json";
    
    /*
     * Parse our arguments; every option seen by parse_opt will be
     * reflected in arguments.
     */
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    
    printf("command: %s\n", arguments.commande);
    
    configuration_parse();
    
    printf("base-url: %s\n\n", configuration.base_url);

    execute();

    return (EXIT_SUCCESS);
}

