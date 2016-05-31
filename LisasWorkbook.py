import math
chapters,maxi = input().strip().split()
chapters, maxi = [int(chapters), int(maxi)]
problems = [int(a) for a in input().strip().split()]
page = 0
count = 0
current_page = 1
current_chapter = 0
while(current_chapter<chapters):
        max_pages = int(math.ceil( problems[current_chapter]/maxi))
        diff = 0
        if problems[current_chapter] >= maxi:
            diff = problems[current_chapter]%maxi
        if problems[current_chapter] < maxi:
            diff = problems[current_chapter]
        if(current_page <= max_pages):
                if current_page == max_pages:
                        problem = current_page + page
                        bound_b = 0
                        bound_a = current_page*maxi-(maxi-1)
                        if diff > 0: 
                            bound_b = bound_a + diff -1
                        if diff == 0:
                            bound_b = current_page*maxi
                        if problem >= bound_a and problem<= bound_b:
                            count+=1
                           
                if current_page < max_pages:
                        problem = current_page + page
                        bound_b = current_page*maxi
                        bound_a = current_page*maxi-(maxi-1)
                        if problem >= bound_a and problem<= bound_b:
                            count+=1
                          
                current_page+=1
                continue
        if(current_page > max_pages):
                current_chapter+=1
                page +=max_pages
                current_page = 1
                continue
        
print(count)           
    
#32
