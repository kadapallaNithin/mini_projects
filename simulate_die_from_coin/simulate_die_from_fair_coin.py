import random
def toss_a_fair_coin():
    if random.random() >= 0.5:
        return 'H'
    return 'T'

def generate_a_set():
    return ''.join([toss_a_fair_coin() for _ in range(3)])

def simulate_die():
    s = generate_a_set()
    if s == 'HHH' or s == 'TTT':
        return simulate_die()
    return {"HHT":1,"HTH":2,"HTT":3,"THH":4,"THT":5,"TTH":6}[s]

def test():
    number_of_rolls = 100000
    counts = [0]*6
    total_count = 0
    for i in range(number_of_rolls):
        outcome = simulate_die()
        counts[outcome-1] += 1
        total_count += 1
    print(round(1/6,3),[round(count/total_count,3) for count in counts])

test()
