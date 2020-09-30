/* Lyndon Renaud
 * 2020-09-30
 * 
 * How I solved this problem:
 * We can partition the set of ballots into voting boxes.
 * No ballot is in more than one ballot box.
 * When a candidate is eliminated, then for each ballot in their box, 
 * we copy the ballot to the next non-eliminated candidate id written on the ballot.
 * Once all ballots in an eliminated candidate's vote box have been copied, we empty 
 * the elimnated candidate's vote box and never look inside it again.
 *
 * How to determine a winner (or group of winners)?
 * We look at the size of all vote boxes of candidates still in the race
 * The set of vote boxes with the largest size = W
 * We also keep track of the amount of eliminated candidates => loser_count
 * There are 3 cases which determine a winner:
 *
 * Case 1: |W| == 1
 * In this case, there is only 1 vote box with the largest size, V.
 * We check if |V| > total_ballots / 2
 * If true, then the candidate belonging to box V is the winner
 * Else owner of box V is not the winner
 * 
 * Case 2: |W| > 1
 * In this case, there are multiple vote boxes with the largest size
 * So we have a collection of largest voting boxes, L
 * If the summation of the sizes of V in L == total_ballots
 * then we have a |L| way tie between the owners of each box V in L
 *
 * Case 3: loser_count == total_candidates - 1
 * In this case, all candidates but 1 have been eliminated.
 * Then the last standing candidate is the winner
 *
 * We continuously eliminated candidates until one of these cases yields a winner
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define DEBUG 0

int main(){
        // get total number of cases
        int total_cases;
        cin >> total_cases;
        if (DEBUG) {cerr << "total cases: " << total_cases << '\n';}
        int case_count = 1;     //REMOVE
        while(total_cases--){
        if (DEBUG) {cerr << "case " << case_count << '\n'; ++case_count;}

        int total_candidates;
        cin >> total_candidates;
        cin.ignore(1000, '\n');
        if (DEBUG) cerr << "total candidates: " << total_candidates << '\n';

        vector<string> names(total_candidates+1);   // store candidate names
        vector<vector<vector<int>>> vote_boxes(total_candidates+1);
        
        // populate candidate names vector
        for(int i = 1; i <= total_candidates; ++i){
                getline(cin, names[i]);
                if (DEBUG) cerr << "reading: " << names[i] << '\n';
        }
        if(DEBUG){
                cerr << "names: ";
                for(int i = 1; i <= total_candidates; ++i){
                        cerr << i << ": " << names[i] << '\n';
                }
        }

        // populate vote_boxes with ballots
        string line;
        int ballot_count = 0;
        for(int i = 0; getline(cin, line); ++i){
                if(DEBUG) cerr << "reading ballot line: " << line << '\n';
                // if we reached end of ballot input, we are done input for this case
                if (line.empty()){
                        if(DEBUG) cerr << "Done reading ballots\n";
                        break;
                }
                if (DEBUG) cerr << "filling ballot " << i << " with values: ";
                stringstream line_stream(line);
                vector<int> ballot(total_candidates);
                int vote;
                for(int j = 0; line_stream >> vote; ++j){
                        if (DEBUG) cerr << vote << ", ";
                        ballot[j] = vote;
                }
                vote_boxes[ballot[0]].push_back(ballot);
                ++ballot_count;
                if (DEBUG) cerr << '\n';
        }
        
        //cerr << "ballot count: " << ballot_count << '\n';

        // prep for first election round
        vector<int> lost(total_candidates+1, 0);        //lost[i] = 1 if candidate i eliminated else 0
        int largest = 0, smallest = ballot_count, first_box = 1, lost_count = 0;
        vector<int> losers, winners;
        int winner_found = 0;

        // while no candidate has # of votes > n/2
        while(!winner_found){
            if(DEBUG){ cerr << "eliminated candidate ids: "; for(int i = 1; i <= total_candidates; ++i){if(lost[i]) cerr << i << ", ";} cerr << '\n';}
            if(DEBUG){ cerr << "vote box sizes:\n"; for(int i = 1; i <= total_candidates; ++i){cerr << "box[" << i << "].size = " << vote_boxes[i].size() << '\n';}}

            // search for largest and smallest vote boxes
            for(int i = 1; i <= total_candidates; ++i){
                // skip eliminated candidates
                if(lost[i] == 1){
                    continue;
                }
                // size of vote box i
                int len = vote_boxes[i].size();

                // if vote box i has largest amount of ballots
                if(len > largest){
                    // check if prev winners will be new losers
                    if(winners.size() > 0){
                        if(largest < smallest){
                            losers = winners;
                            smallest = largest;
                        }
                        else if(largest == smallest){
                            losers.insert(losers.end(), winners.begin(), winners.end());
                        }
                    }
                    // update winners array
                    winners.clear();    // remove previous winners
                    winners.push_back(i);
                    largest = len;
                }

                // if vote box i size == current largest (group of winners)
                else if(len == largest){
                    winners.push_back(i);
                }

                // if vote box i has smaller amount of ballots than current smallest
                else if(len < smallest){
                    losers.clear();     // prev losers have more ballots than box i
                    losers.push_back(i);    // losers = {i}
                    smallest = len; // update smallest ballot count
                }

                // if vote box i has size == smallest
                else if(len == smallest){
                    losers.push_back(i);
                }
            }   // end ballot count

            // Now we search for a winner
            // We sum the ballots of all vote boxes in the winner group
            if(DEBUG) {cerr << "SEARCHING FOR A WINNER\n";}
            int total_winner_votes = 0;
            for(auto i : winners){
                total_winner_votes += vote_boxes[i].size();
            }

            // we may have a group tie, so we check
            if(winners.size() > 1){
                // for x, y in winners, x.size == y.size
                // if the summation of the sizes of winners == total_ballots, 
                // we have a winning tie
                if(total_winner_votes == ballot_count){
                    if(DEBUG){cerr << "WINNERS FOUND\n";}
                    winner_found = 1;
                    break;
                }
            }

            // if winners set is a singleton, we check if winner has > %50 votes
            if(winners.size() == 1 && total_winner_votes > static_cast<float>(ballot_count) / 2.0){
                if(DEBUG) {cerr << "WINNER FOUND\n";}
                winner_found = 1;
                break;
            }

            // else we have no winner
            else{
                if(DEBUG) {cerr << "NO WINNER FOUND\n";}
                // update the lost array. lost[eliminated_id] = 1
                for(auto l : losers){
                    lost[l] = 1;
                    ++lost_count;
                }

                // for each loser
                for(auto l : losers){
                    // move their ballots to the next non-loser box
                    if(DEBUG){cerr << "SHIFTING BALLOTS FOR LOSER " << l << '\n';}
                    for(auto ballot : vote_boxes[l]){
                        int next = 0;
                        for(; next < total_candidates; ++next){
                            if(lost[ballot[next]] == 0){
                                break;
                            }
                        }
                        if(DEBUG){cerr << "MOVING BALLOT " << l << " TO BOX " << next << '\n';}
                        vote_boxes[ballot[next]].push_back(ballot);
                    }
                    // then empty the losers box
                    vote_boxes[l].clear();
                }
                if(DEBUG){cerr << "FINISHED SHIFTING LOSER BALLOTS\n";}

                // it is possible that all but one candidates have been eliminated
                // in this case, the non-eliminated cand is the winner
                if(lost_count == total_candidates-1){
                    winners.clear();
                    // we search for the non-eliminated candidate
                    for(int w = 1; w <= total_candidates; ++w){
                        if(lost[w] == 0){
                            winners.push_back(w);
                        }
                    }
                    // then break from loop as the winner has been found
                    if(DEBUG) {cerr << "WINNER FOUND\n";}
                }
            }
            //prepare for the next roundi
            if(!winner_found){
                winners.clear();
                losers.clear();
                largest = 0;
                smallest = ballot_count;
            }
        }// while loop exit once winner found
        if(DEBUG){cerr << "EXITED CASE AS WINNER HAS BEEN FOUND\n";}
        for(auto id : winners){
                cout << names[id] << '\n';
        }
        // dont print a new line after the last case
        if(total_cases > 0){
            cout << '\n';
        }
         
        } // end while
        return 0;
}
