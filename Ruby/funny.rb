def haveMoreFun(a)
  puts "a Identification berfore manipulation #{a.object_id}"
  a = a + 1
  puts "a Identification after manipulation #{a.object_id}"
  puts "In function a = #{a} : #{a.class}"
end

a = 1
puts "a Identification berfore passing #{a.object_id}"
haveMoreFun(a)
puts "In main a = #{a} : #{a.class}"
