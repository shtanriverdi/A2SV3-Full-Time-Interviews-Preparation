import sys
input = sys.stdin.readline
 
from collections import defaultdict
 
def main():
    n = int(input())
 
    name_list = []
    score_map = defaultdict(int)
    for i in range(n):
        nameScore = list(input().split())
        name = str(nameScore[0])
        score = int(nameScore[1])
        score_map[name] += score
        name_list.append((name, score))
 
    max_score = float("-inf")
    for name, score in score_map.items():
        max_score = max(score_map[name], max_score)
        
    players_has_max_score = set()
    for name, score in score_map.items():
        if score == max_score:
            players_has_max_score.add(name)
 
    final_map = defaultdict(int)
    for name, score in name_list:
        final_map[name] += score
        if final_map[name] >= max_score and name in players_has_max_score:
            print(name)
            break
 
if __name__ == "__main__":
    main()