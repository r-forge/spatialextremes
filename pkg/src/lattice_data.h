
  const int primeNumbers[1000] = {
				2,   3,   5,   7,  11,  13,  17,  19,  23,  29,
				31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
				73,  79,  83,  89,  97, 101, 103, 107, 109, 113,
				127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
				179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
				233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
				283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
				353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
				419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
				467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
				547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
				607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
				661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
				739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
				811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
				877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
				947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013,
				1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063,
				1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123,
				1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201,
				1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277,
				1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319,
				1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423,
				1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471,
				1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531,
				1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597,
				1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657,
				1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723,
				1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789,
				1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873,
				1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949,
				1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011,
				2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083,
				2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141,
				2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237,
				2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293,
				2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357,
				2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417,
				2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503,
				2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591,
				2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663,
				2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711,
				2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777,
				2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843,
				2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917,
				2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001,
				3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079,
				3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169,
				3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251,
				3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319,
				3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373,
				3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463,
				3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533,
				3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593,
				3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671,
				3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733,
				3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821,
				3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889,
				3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947,
				3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027,
				4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111,
				4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201,
				4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259,
				4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339,
				4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423,
				4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507,
				4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583,
				4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651,
				4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729,
				4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801,
				4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909,
				4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969,
				4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023,
				5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107,
				5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197,
				5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281,
				5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387,
				5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441,
				5443, 5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507,
				5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581,
				5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659,
				5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741,
				5743, 5749, 5779, 5783, 5791, 5801, 5807, 5813, 5821,
				5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869,
				5879, 5881, 5897, 5903, 5923, 5927, 5939, 5953, 5981,
				5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067,
				6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133,
				6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217,
				6221, 6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287,
				6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353,
				6359, 6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427,
				6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547,
				6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607,
				6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 6691,
				6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779,
				6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 6841,
				6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917,
				6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991,
				6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069,
				7079, 7103, 7109, 7121, 7127, 7129, 7151, 7159, 7177,
				7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243,
				7247, 7253, 7283, 7297, 7307, 7309, 7321, 7331, 7333,
				7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457,
				7459, 7477, 7481, 7487, 7489, 7499, 7507, 7517, 7523,
				7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577,
				7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649,
				7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723,
				7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823,
				7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901,
				7907, 7919};

const double sqrtPrimeNumbers[1000] = {
				1.414213562373095, 1.732050807568877, 2.236067977499790,
				2.645751311064591, 3.316624790355400, 3.605551275463989,
				4.123105625617661, 4.358898943540674, 4.795831523312719,
				5.385164807134504, 5.567764362830022, 6.082762530298219,
				6.403124237432849, 6.557438524302000, 6.855654600401044,
				7.280109889280518, 7.681145747868608, 7.810249675906654,
				8.185352771872450, 8.426149773176359, 8.544003745317530,
				8.888194417315589, 9.110433579144299, 9.433981132056603,
				9.848857801796104, 10.049875621120890, 10.148891565092219,
				10.344080432788601, 10.440306508910551, 10.630145812734650,
				11.269427669584644, 11.445523142259598, 11.704699910719626,
				11.789826122551595, 12.206555615733702, 12.288205727444508,
				12.529964086141668, 12.767145334803704, 12.922847983320086,
				13.152946437965905, 13.379088160259652, 13.453624047073710,
				13.820274961085254, 13.892443989449804, 14.035668847618199,
				14.106735979665885, 14.525839046333950, 14.933184523068078,
				15.066519173319364, 15.132745950421556, 15.264337522473747,
				15.459624833740307, 15.524174696260024, 15.842979517754859,
				16.031219541881399, 16.217274740226856, 16.401219466856727,
				16.462077633154330, 16.643316977093239, 16.763054614240211,
				16.822603841260722, 17.117242768623690, 17.521415467935231,
				17.635192088548397, 17.691806012954132, 17.804493814764857,
				18.193405398660254, 18.357559750685819, 18.627936010197157,
				18.681541692269406, 18.788294228055936, 18.947295321496416,
				19.157244060668017, 19.313207915827967, 19.467922333931785,
				19.570385790780925, 19.723082923316021, 19.924858845171276,
				20.024984394500787, 20.223748416156685, 20.469489490458720,
				20.518284528683193, 20.760539492026695, 20.808652046684813,
				20.952326839756964, 21.047565179849187, 21.189620100417091,
				21.377558326431949, 21.470910553583888, 21.517434791350013,
				21.610182784974310, 21.886068628239290, 22.068076490713910,
				22.158519806160339, 22.338307903688676, 22.427661492005804,
				22.561028345356956, 22.825424421026653, 22.869193252058544,
				23.259406699226016, 23.388031127053001, 23.600847442411894,
				23.727621035409346, 23.853720883753127, 23.895606290697042,
				24.020824298928627, 24.228082879171435, 24.351591323771842,
				24.474476501040833, 24.515301344262525, 24.637369989509839,
				24.758836806279895, 24.839484696748443, 24.879710609249457,
				25.119713374160941, 25.317977802344327, 25.357444666211933,
				25.436194683953808, 25.553864678361276, 25.670995305986871,
				25.709920264364882, 25.942243542145693, 26.019223662515376,
				26.134268690743959, 26.286878856189830, 26.476404589747453,
				26.627053911388696, 26.814175355583846, 26.962937525425527,
				27.073972741361768, 27.184554438136374, 27.258026340878022,
				27.404379212089442, 27.513632984395208, 27.586228448267445,
				27.730849247724095, 27.802877548915689, 28.053520278211074,
				28.231188426986208, 28.442925306655784, 28.478061731796284,
				28.653097563788805, 28.687976575562104, 28.757607689096812,
				28.792360097775937, 28.965496715920477, 29.206163733020468,
				29.274562336608895, 29.308701779505689, 29.376861643136763,
				29.614185789921695, 29.681644159311659, 29.715315916207253,
				29.782545223670862, 30.116440692751194, 30.182776545573141,
				30.315012782448235, 30.479501308256342, 30.610455730027933,
				30.675723300355934, 30.773365106858236, 30.870698080866262,
				31.096623610932426, 31.160872901765767, 31.256999216175569,
				31.352830813181765, 31.480152477394387, 31.575306807693888,
				31.764760348537180, 31.827660925679098, 31.921779399024736,
				31.953090617340916, 32.109188716004645, 32.140317359976393,
				32.233522922572398, 32.388269481403292, 32.419130154894653,
				32.572994949804659, 32.603680773802211, 32.695565448543633,
				32.969683043669072, 33.030289129827487, 33.060550509633082,
				33.120990323358392, 33.211443810831227, 33.301651610693426,
				33.421549934136806, 33.511192160232078, 33.600595232822883,
				33.926390907374746, 33.955853692699293, 34.102785809959869,
				34.219877264537345, 34.365680554879162, 34.452866353904433,
				34.539832078341085, 34.655446902326915, 34.828149534535996,
				34.885527085024819, 34.971416900091420, 35.057096285916209,
				35.085609585697668, 35.171010790137949, 35.341194094144583,
				35.482389998420345, 35.735136770411273, 35.763109484495331,
				35.818989377144632, 35.902646142032481, 35.930488446443363,
				36.013886210738214, 36.069377593742864, 36.097091295560091,
				36.152454965050438, 36.318039594669756, 36.345563690772494,
				36.428011200173970, 36.891733491393431, 36.972963094672302,
				37.054014627297811, 37.161808352124091, 37.403208418530085,
				37.536648758246919, 37.722672227720032, 37.775653535048207,
				37.802116342871599, 37.854986461495400, 37.934153476781319,
				38.039453203220468, 38.091993909481822, 38.118237105091836,
				38.196858509568557, 38.353617821530214, 38.483762809787713,
				38.509739027939411, 38.561638969317684, 38.587562763149478,
				38.639358172723313, 38.716921365211881, 38.871583451153619,
				39.025632602175712, 39.127995093027700, 39.281038682804713,
				39.357337308308857, 39.408120990476064, 39.484174044799268,
				39.585350825778974, 39.635842365212831, 39.736632972611055,
				39.786932528155525, 39.962482405376171, 40.012498047485110,
				40.087404505654888, 40.112342240263160, 40.162171256046406,
				40.236799077461420, 40.261644278394790, 40.336088060197412,
				40.459856648287818, 40.706264874095240, 40.779897008207364,
				40.828911325187207, 40.853396431630991, 41.146081222881968,
				41.194659848091959, 41.218927691049899, 41.340053217188775,
				41.484937025383083, 41.509035161034518, 41.629316592997299,
				41.725292090050132, 41.797129088012731, 41.868842830916641,
				41.940433951021539, 42.154477816715982, 42.225584661434823,
				42.272922775696500, 42.296571965113202, 42.438190347845890,
				42.555845661906424, 42.696604080418389, 42.790185790669334,
				42.976737893888597, 43.139309220245984, 43.208795400936602,
				43.255057507764334, 43.278170016764804, 43.324358044868937,
				43.347433603386484, 43.462627624201460, 43.600458713183279,
				43.669211121796096, 43.737855457258078, 43.943145085439660,
				43.965895873961216, 44.147480109288232, 44.170125650715555,
				44.418464629025621, 44.485952839070450, 44.575778176045340,
				44.643028571099428, 44.687805943008662, 44.710177812216315,
				44.754888001200491, 44.844174649557324, 44.911023145771239,
				45.022216737961713, 45.044422518220834, 45.155287619502545,
				45.310043036836767, 45.420259796703057, 45.486261662176638,
				45.617978911828175, 45.639894828976104, 45.683695122001680,
				45.705579528105758, 45.814844755821227, 45.945620030640569,
				45.967379738244816, 46.141087980237309, 46.162755550335163,
				46.227697325304881, 46.270941205037097, 46.292547996410825,
				46.400431032480725, 46.486557196677836, 46.679760067935227,
				46.936126810805341, 46.978718586185380, 47.042533945356304,
				47.127486671792717, 47.296934361541872, 47.318072657283921,
				47.360320944858472, 47.444704657105831, 47.613023428469653,
				47.634021455258214, 47.675989764240867, 47.759815745038210,
				47.822588804873369, 47.885279575251516, 47.927027865287037,
				48.052055106935853, 48.072861366887658, 48.301138702933287,
				48.363209157374989, 48.383881613611777, 48.445846055157297,
				48.487111689602628, 48.548944375753422, 48.692915295759406,
				48.754486972995622, 48.795491595023407, 48.815980989835694,
				48.877397639399746, 48.918299234540036, 48.979587585033826,
				49.101934788763671, 49.162994213127419, 49.223977896955873,
				49.365980188789933, 49.406477308142499, 49.467160824126545,
				49.588305072869751, 49.668903752750573, 49.729267036625423,
				49.769468552517218, 50.029991005395956, 50.209560842532767,
				50.309044912421065, 50.388490749376487, 50.428166732491874,
				50.487622245457352, 50.507425196697561, 50.566787519082126,
				50.783855702378489, 50.901866370497650, 50.921508225896062,
				51.078371156488537, 51.156622249714651, 51.195702944680818,
				51.312766442669997, 51.449003877626240, 51.546095875439491,
				51.565492337414952, 51.604263389762671, 51.681718237690198,
				51.739733281106119, 51.797683345879477, 51.836280730777744,
				51.855568649856693, 51.894122981316485, 51.951900831442153,
				52.028838157314254, 52.067264187779251, 52.086466572421671,
				52.144031297934760, 52.239831546435909, 52.258970521815677,
				52.354560450833695, 52.430906915673319, 52.469038489379621,
				52.602281319349636, 52.697248505021591, 52.810983706043572,
				52.829915767489162, 52.886671288709408, 52.924474489596967,
				52.943365967796190, 53.094255809833136, 53.225933528685054,
				53.263495942343098, 53.319789947073126, 53.394756296849977,
				53.450912059571067, 53.488316481265329, 53.656313701185248,
				53.730810528038752, 53.823786563191554, 53.879495172096775,
				53.935146240647200, 54.009258465563107, 54.101755978895916,
				54.212544673719201, 54.341512676774101, 54.378304497290095,
				54.433445601027316, 54.488530903301111, 54.506880299646575,
				54.763126280372269, 54.781383699209350, 54.872579673275794,
				54.945427471264615, 54.981815175565096, 55.108982933819419,
				55.145262715848951, 55.217750769114090, 55.326304774492215,
				55.380501984001555, 55.488737596020329, 55.524769247606962,
				55.578772926361012, 55.758407437802596, 55.848008021772806,
				55.865910893853687, 56.008927859761783, 56.240554762555462,
				56.276105053566027, 56.293871780150276, 56.400354608814297,
				56.453520705089772, 56.488936969994398, 56.595052787324086,
				56.648036153074187, 56.718603649948932, 56.753854494650845,
				56.824290580701486, 57.017541160593730, 57.035076926396798,
				57.070132293521098, 57.087651904768336, 57.192656871315222,
				57.436921923097515, 57.454329688892898, 57.506521369319501,
				57.558665724632640, 57.610762883336307, 57.645468165329355,
				57.697486947006624, 57.714816122032303, 57.818682101895057,
				57.853262656482912, 57.956880523368405, 57.974132162542979,
				58.060313467979142, 58.077534382926416, 58.215118311311535,
				58.232293446162672, 58.369512590049951, 58.420886675914119,
				58.591808301161009, 58.728187440104094, 58.796258384356399,
				58.830264320330912, 58.847259919217990, 58.881236400062114,
				58.898217290508889, 59.084684986889791, 59.152345684681009,
				59.253691868102194, 59.304300012730948, 59.388551085204966,
				59.405386961116584, 59.439044406854322, 59.489494870943389,
				59.506302187247357, 59.556695677312391, 59.640590204993778,
				59.657354953098618, 59.757844673314651, 59.841457201508724,
				59.858165691908738, 59.941638282582836, 60.058305004387194,
				60.108235708594876, 60.141499815019579, 60.191361506448750,
				60.257779580731317, 60.307545133258408, 60.357269653290317,
				60.489668539346454, 60.588777838804440, 60.605280298007038,
				60.638271743182131, 60.753600716336145, 60.802960454241045,
				60.835844697020519, 60.901559914340453, 60.983604353957304,
				61.049160518388781, 61.098281481560512, 61.147362984841791,
				61.326992425847855, 61.375891032228608, 61.392181912683313,
				61.473571557214733, 61.587336360651285, 61.619802012015583,
				61.668468442146349, 61.814237842102365, 61.830413228442843,
				61.911226768656427, 62.024188829842828, 62.056425936400814,
				62.072538211353979, 62.153036933041335, 62.265560304232388,
				62.297672508690084, 62.361847310675458, 62.505999712027645,
				62.537988455018279, 62.585940913275401, 62.601916903558156,
				62.633856659158390, 62.681735776859277, 62.697687357668940,
				62.793311745758402, 62.825154197980289, 62.984124983998946,
				63.158530698552511, 63.253458403473878, 63.269265840532718,
				63.300868872393842, 63.348243858847418, 63.395583442381849,
				63.411355449950761, 63.458647952820428, 63.631753079732135,
				63.647466563878254, 63.694583757176716, 63.820059542435402,
				63.867049407343060, 63.960925571789531, 63.976558206893252,
				64.023433210036458, 64.117080407641765, 64.241730985396089,
				64.257295305669373, 64.288412641781719, 64.335060425867326,
				64.443773942872099, 64.474801279259481, 64.490309349544916,
				64.629714528226103, 64.815121692395209, 64.892218331630488,
				64.938432380216881, 64.953829756219918, 65.030761951556428,
				65.046137471797664, 65.122960620659740, 65.138314377945022,
				65.215028942721474, 65.261014396038931, 65.276335681470357,
				65.352888229978021, 65.368187981616870, 65.444633087824698,
				65.490457320131767, 65.551506466289538, 65.779936150774731,
				65.855903304107827, 65.871086221497819, 65.946948375190189,
				66.007575322836999, 66.053009015486950, 66.128662469461759,
				66.264621028117261, 66.309878600401618, 66.400301204136113,
				66.490600839517157, 66.505638858671219, 66.640828326184547,
				66.685830578916836, 66.715815216483719, 66.760766921898067,
				66.805688380556333, 66.940271884718243, 66.955208908642803,
				67.029844099475568, 67.134193969988203, 67.178865724273734,
				67.208630398186216, 67.223507793033235, 67.253252709441497,
				67.431446669932868, 67.446274915668994, 67.535176019612180,
				67.579582715491810, 67.697858164051240, 67.756918465939691,
				67.801179930735714, 67.845412519933873, 67.977937597429360,
				68.095521144932874, 68.110204815431288, 68.139562663697802,
				68.183575734923139, 68.198240446510056, 68.242215673291270,
				68.286162580716166, 68.359344642850402, 68.403216298650747,
				68.490875304671064, 68.578422262399712, 68.709533545207535,
				68.724086025206617, 68.767724987816777, 68.796802251267465,
				68.927498141162786, 68.985505724028727, 69.159236548706929,
				69.188149274279624, 69.202601107183824, 69.231495722683903,
				69.274815048471979, 69.289248805280025, 69.375788283809797,
				69.404610797842537, 69.505395474020574, 69.720872054213430,
				69.792549745656956, 69.835521047673154, 69.921384425653358,
				70.021425292548855, 70.064256222413434, 70.135582980395910,
				70.221079456243046, 70.235318750611498, 70.263788682364691,
				70.306471963824208, 70.363342729009119, 70.405965656327737,
				70.476946585390607, 70.491134194308430, 70.519500849055930,
				70.618694408775355, 70.661163307718056, 70.703606697254131,
				70.731888141064076, 70.774289116881988, 70.788417131618360,
				70.859014952227497, 70.873126077519686, 70.985914095685203,
				71.070387644925646, 71.126647608333130, 71.253070109294242,
				71.281133548786940, 71.323208004127238, 71.407282541768808,
				71.421285342676384, 71.463277282811489, 71.505244562899023,
				71.547187226333364, 71.742595436741766, 71.784399419372448,
				71.881847499907792, 71.909665553387185, 71.965269401288282,
				72.034713853808015, 72.090221250874237, 72.173402303064520,
				72.297994439679997, 72.325652433973943, 72.339477465627297,
				72.367119605522504, 72.532751223154364, 72.615425358528341,
				72.656727148970859, 72.670489196096653, 72.780491891715045,
				72.821700062550036, 72.862884927787476, 72.958892535454510,
				73.027392121039071, 73.123183738127821, 73.150529731506381,
				73.355299740373226, 73.396185186970044, 73.437047870948632,
				73.477887830285383, 73.532305825398950, 73.573092907665639,
				73.600271738628791, 73.613857391118970, 73.695318711570820,
				73.736015623303103, 73.763134423640111, 73.776690085690348,
				73.817342135842310, 73.966208500909389, 74.006756448313553,
				74.020267494788214, 74.047282191853611, 74.168726563154635,
				74.182208109492137, 74.209163854607610, 74.289972405433019,
				74.303431953039691, 74.343795975185444, 74.370693152612205,
				74.545288248151536, 74.585521383174637, 74.625732827222535,
				74.652528423356159, 74.706090782479038, 74.772989775720490,
				74.986665481270734, 75.093275331416990, 75.106590922501596,
				75.146523539016755, 75.173133498611051, 75.186434946737563,
				75.213030785895072, 75.226325179421067, 75.292761936324268,
				75.385675031798982, 75.425459892532302, 75.451971478550519,
				75.504966724050675, 75.571158519636313, 75.610845782863720,
				75.742986473996396, 75.769386958058462, 75.782583751149573,
				75.822160349069449, 76.019734279988114, 76.046038687100591,
				76.098620224022454, 76.164296097318456, 76.203674452089246,
				76.243032468547582, 76.295478240849903, 76.334788923530795,
				76.413349619029262, 76.439518575145414, 76.478755219995577,
				76.491829629052546, 76.531039454589930, 76.557168181692816,
				76.596344560298704, 76.609398901179219, 76.674637266830288,
				76.687678280151374, 76.791926658991954, 76.830983333548446,
				76.961029099148618, 76.987011891617144, 77.064907707723890,
				77.155686763841331, 77.336925203941234, 77.375706781909273,
				77.504838558634518, 77.530639104808103, 77.646635471216655,
				77.698133825723247, 77.736735202862747, 77.762458808862263,
				77.801028270839709, 77.890949410056621, 77.929455278476055,
				77.967942130083188, 78.032044699597620, 78.044858895381438,
				78.108898340714035, 78.185676437567508, 78.236819976274603,
				78.300702423413796, 78.313472659562223, 78.377292629944805,
				78.428311214764790, 78.504776924719678, 78.568441501661468,
				78.721026416072604, 78.733728477698804, 78.759126455287713,
				78.809897855535894, 78.847954951285828, 78.873316146843990,
				78.924014089502563, 79.037965560861949, 79.101201002260396,
				79.139118013786330, 79.177016867270268, 79.189645787817483,
				79.227520471109031, 79.290604739779852, 79.366239674057880,
				79.378838489864535, 79.441802597876645, 79.479557120054466,
				79.517293716524335, 79.555012412795207, 79.605276207045478,
				79.642953235047727, 79.705708703956702, 79.743338279758518,
				79.755877526361658, 79.793483443198539, 79.831071645068121,
				79.868642156981736, 79.931220433570260, 79.981247802219244,
				80.131142510262507, 80.168572395920833, 80.305666051655408,
				80.318117507820119, 80.430093870391573, 80.454956342042721,
				80.504658250314932, 80.566742518237632, 80.752708932889675,
				80.802227692063042, 80.913534096589800, 80.938248066041069,
				80.950602221354728, 81.012344738317509, 81.049367671808525,
				81.061704892014205, 81.098705291761590, 81.123362849428275,
				81.234229238665151, 81.283454650992780, 81.357236924566209,
				81.467785044151043, 81.565924257621205, 81.602696033893395,
				81.614949610962825, 81.688432473637292, 81.725149128037685,
				81.786306922369349, 81.798532994180277, 81.859635963031252,
				81.871851084484462, 81.908485518900903, 81.969506525292687,
				82.054859697643749, 82.079230015881606, 82.225300242686856,
				82.237461050302372, 82.334682849938758, 82.346827504160714,
				82.407523928340424, 82.419657849326214, 82.480300678404419,
				82.601452771727935, 82.625661873294547, 82.637763764516279,
				82.661962231730257, 82.710337927008865, 82.807004534640669,
				82.843225432137785, 82.879430499973878, 82.891495341802099,
				82.963847548194153, 83.060219118420335, 83.108362996752618,
				83.132424480463698, 83.168503653726987, 83.348665256259508,
				83.360662185469707, 83.420620951896538, 83.432607534464609,
				83.468556954100990, 83.492514634546737, 83.528438271046340,
				83.564346464266691, 83.612200066736676, 83.648072302952684,
				83.671978583035795, 83.743656476177350, 83.779472426125963,
				83.827203221865872, 83.898748500797083, 83.922583373011108,
				84.005952170069477, 84.077345343439575, 84.136793378402530,
				84.279297576569775, 84.314885992925355, 84.386017799159120,
				84.421561226975655, 84.433405711246778, 84.563585543660579,
				84.610874005650132, 84.717176534631989, 84.776175898656817,
				84.811555816409836, 84.894051617295304, 84.917607125966526,
				84.929382430346209, 84.964698551810329, 85.023526155999903,
				85.070558949615460, 85.105816487476346, 85.129313400261836,
				85.164546614186818, 85.340494491185126, 85.422479477008864,
				85.480992039166225, 85.492689745966004, 85.562842402528915,
				85.621259042366347, 85.632937588290176, 85.726308680591160,
				85.737972917488548, 85.842879728024030, 85.982556370463882,
				86.087165129303685, 86.122006479180456, 86.214847909162373,
				86.319175158246267, 86.353922898731128, 86.365502372185617,
				86.469647854030256, 86.492774264674850, 86.527452291165957,
				86.539008545279742, 86.596766683289047, 86.642945471630867,
				86.700634369074834, 86.735229290064140, 86.769810418140253,
				86.815897161752588, 86.838931361457924, 86.873471209570070,
				86.884981440983225, 86.942509740632630, 86.954010833313490,
				87.022985469357465, 87.045964869142551, 87.080422598882691,
				87.114866699088736, 87.126345039832813, 87.195183353210510,
				87.218117383947245, 87.298339044909667, 87.401372986927385,
				87.424252927891814, 87.458561616344909, 87.572826835725706,
				87.595661993046207, 87.641314458421945, 87.675538207643754,
				87.698346620674670, 87.743945660085288, 87.766736295706011,
				87.846456957580259, 87.880600817245210, 87.903356022395414,
				87.982952894296517, 88.051121514720066, 88.073832663283142,
				88.085186041694882, 88.255311454892052, 88.277970071813499,
				88.413799827854930, 88.447724673956429, 88.481636512894582,
				88.549421229051518, 88.617154095581284, 88.696110399498352,
				88.729927307532492, 88.752464754506960, 88.763731332115597,
				88.786260198298706, 88.887569434651553, 88.921313530559146,
				88.988763335603224
};
