#include "cce.h"

/*
Riley.Porter@g2-inc.com & Matthew.Kerr@g2-inc.com
 *
 *Open Scap
 *Notes:  No current error checking is implemented during malloc calls.
 *
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/







int main( int argc, const char* argv[] )
{
	printf("CCE XML Parsing Program:\n");
	struct CCE cce;
	initCCE(&cce);

         if (argc != 3)

        {
            printf("Invalid Syntax Usage:\n Syntax: ./cce_parse filen.xml CCE-xxxx-x");
        }
        

        char* docname = argv[1]; //The CCE XML file to be parsed. (searched)
        char* id = argv[2]; //2nd Argument is the CCE ID to be searched for.

        printf("Searching for %s\n\n",id);
        
        validateFile(docname);
        parseDoc (docname, &cce, id);

        //Example of struct data returned.
        printf("\nID: %s\n",cce.id);
        printf("Description: %s\n",cce.description);

        struct list_XMLCHAR* current = cce.references;
        while(current)
            {
                printf("Ref Source: %s\n",cce.references->source);
                printf("Ref Value: %s\n",cce.references->value);
                current = current->next;
            }

        current = cce.technicalmechanisms;
            while(current)
            {
                printf("Technical Mech: %s\n",current->value);
                current = current->next;
            }

        current = cce.parameters;
            while(current)
            {
                printf("Available Parameter Choices: %s\n",current->value);
                current = current->next;

            }

	clearCCE(&cce); //cce is a struct that contains all the data that the ID string contained.

	return 0;
}


