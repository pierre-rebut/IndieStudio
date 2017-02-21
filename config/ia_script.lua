n = 0
math.randomseed(os.time())
math.random()
math.random()
math.random()
function randomize()
	 n = n + 1
	 if n == 300
	 then
		n = 0
		toto = math.random(50, 80)
		tmp = math.fmod(toto, 2)
		return(tmp)
	 end
	 return(5)
	end
