class Person
	attr_accessor :name, :age, :gender
	def hello(i)
		i.times do
			puts "hello"
		end
	end
end
person_instance = Person.new
person_instance.name = "Parham"
puts person_instance
person_instance.hello(3)

puts 10.times
