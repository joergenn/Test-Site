print 'buna ziua eu vand branza'
# ex2
food = Array['bacon', 'orange', 'apple']

# ex3
print 'First element - ', food.first, "\n"

# ex4
puts "Last element - #{food.last}"        # output using interpolation

# ex5
food.push('yogurt')

print 'Array: ', food, "\n"

# ex6
countries = { UK: 'Ukraine',     
              IT: 'Italy', 
              PT: 'Portugal' }
                                          # 2 examples of outputing the hash:
puts countries[:UK]                       
countries.each_pair {|key, value| puts "#{key}: #{value}"}

#ex7
s = 'course'
s = s.gsub!('ourse','anada').upcase

puts s

s_1 = 'course'                            # second way using split method,                                      
s_1 = s_1.split('o')                      # chomp! method works as well
s_1 = s_1[0].upcase<<'anada'.upcase

puts s_1

