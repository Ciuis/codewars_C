/*
You are a big fan of Formula 1.

There was a race last week-end, but ... you missed the live TV. You picked on the internet a list of the events during the race, and you want to get your champion's rank at the end of the race.

An event is a pilot ID followed by a type. There are two types of events:

'O' : a pilot is overtaking the one just in front of him
'I' : a pilot had an incident... and is forced to quit the race (and subsequently all pilots after this one gain one rank)

The list of events is passed as a string where events are separated with a space, first event first. e.g: "2 O 12 I" means the pilot#2 overtook, then the pilot#12 had an incident.

Your function will return the rank of your champion at the end of the race, given your champion's ID (as int) and the list of events. Return -1 if your champion had an incident.

NOTES:

there are 20 positions when the race starts (from 1 to 20, 1 being the one in front),
therefore, the rank of a pilot, at start and during the race, is actually his/her position (first pilot at position 1, etc...),
each pilot ID is his position when the races starts,
        all events in entry lists are syntactically valid.

Final tests contains about 20 fixed events, and 100 random tests with race length between 10 to 30 events. In the tests (fixed and random): the leading pilot never overtakes, and after having an incident, the pilot never appears in further events.*/
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int position;
} Pilot;

int champion_rank (int champion_ID, const char *events);

int main(void) {
    printf("%d\n", champion_rank(2, "9 O 17 O 9 O 12 O 2 O 12 O 9 O 1 O 5 O 12 O 17 O 20 O 16 O 7 O 2 O 8 O 16 O 14 O 3 O 14 O 11 O 16 O 1 O 13 O 8 O 14 O 5 O 12 O 4 O"));
}

int champion_rank(int champion_ID, const char *events) {
    int positions[20];
    for (int i = 0; i < 20; i++) {
        positions[i] = i + 1;
    }

    int pilot_id;
    char event_type;

    while (sscanf(events, "%d %c", &pilot_id, &event_type) == 2) {
        if (event_type == 'O') {
            for (int i = 0; i < 20; i++) {
                if (positions[i] == pilot_id) {
                    int temp = positions[i - 1];
                    positions[i - 1] = pilot_id;
                    positions[i] = temp;
                    break;
                }
            }
        } else if (event_type == 'I') {
            if(pilot_id == champion_ID){
                return -1;
            }
            for (int i = 0; i < 20; i++) {
                if (positions[i] == pilot_id) {
                    for (;i < 19; i++) {
                        positions[i] = positions[i + 1];
                    }
                    break;
                }
            }
        }

        events = strchr(events, ' ');
        events++;
        events = strchr(events, ' ');
        if (!events) break;
        events++;
    }

    for (int i = 0; i < 19; i++) { // There are only 19 pilots left
        if (positions[i] == champion_ID) return i + 1;
    }

    return -1;
}

/*
int champion_rank(int champion_ID, const char* events) {
    Pilot pilots[20];
    for (int i = 0; i < 20; i++) {
        pilots[i].id = i + 1;
        pilots[i].position = i + 1;
    }

    int current_position = champion_ID - 1;

    char event[4];
    int event_index = 0;

    for (int i = 0; i < strlen(events); i++) {
        if (events[i] == ' ') {
            event[event_index] = '\0';
            int pilot_id = 0;
            for (int j = 0; j < strlen(event); j++) {
                pilot_id = pilot_id * 10 + (event[j] - 'O');
            }
            event_index = 0;

            if (events[i + 1] == 'O') {
                if (pilot_id == champion_ID) {
                    Pilot temp = pilots[current_position - 1];
                    pilots[current_position - 1] = pilots[current_position];
                    pilots[current_position] = temp;
                    current_position--;
                } else if (pilot_id == champion_ID - 1) {
                    current_position++;
                }
            } else if (events[i + 1] == 'I') {
                if (pilot_id == champion_ID) return -1;
                else if (pilot_id < champion_ID) current_position--;
            }

            i += 2;
        } else {
            event[event_index++] = events[i];
        }
    }

    return current_position + 1;
}*/
