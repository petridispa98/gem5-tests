# 2nd-Lab

Ο gem5 χρησιμοποιεί τα παρακάτω χαρακτηριστικά μνήμης επεξεργαστή:
L1 instruction cache με size=32768B, assoc=2 και block_size=64B
L1 data cache με size=65536B, assoc=2 και block_size=64B
L2 cache με size=2097152B, assoc=8 και block_size=64B

Στον φάκελος spec_results υπάρχουν τα output των gem5 simulations για κάθε benchmark. Μέσα στον κάθε φάκελο υπάρχει αρχείο info.txt που περιέχει τις πληροφορίες: sim_seconds, cache.overall_miss_rate::total για κάθε είδος cache.Παρατηρώ ότι τα προγ
ράμματα έχουν χαμηλό l1i  missrate οι αυξομοιώσεις του οποίου δεν επηρεάζουν τον χρόνο εκτέλεσης.Αντίθετα l1d,l2 missrate φαινεται να σχετίζονται στενά  με τον  χρόνο εκτέλεσης.

3.Σχετικά με τις εισαγωγές system clk και  cpu clk  η μεν δεύτερη ειναι η ταχύτητα του  επεξεργαστή ενώ η πρώτη αφορά τη
συχνότητα λειτουργίας των υπόλoιπων λειτουργικων μοναδων του συστηματος (πχ membus).
Αναζητώντας πληροφορίες στο αρχείο config.json συλλέξαμε τις εξής : 1) membus, dvfs handler(dynamic voltage frequency scaling)
,tags(της μνήμης) χρονίζονται στη ταχύτητα system clk domain.  
2) cpu ,tol2bus ,walker  χρονίζονται στη συχνότητα system cpu clk domain.
Κατά την αναζήτηση μελετήσαμε τα block των κλασεων (cpu ,system κτλπ) ,όπου προέκυψαν οι παραπάνω ταχύτητες ως τιμές
αρχικοποίησης των κλάσεων αυτών.
Αν προσθέταμε ακόμα έναν επεξεργαστή αυτος θα χρονιζόταν στην τιμή system cpu clk.

Scaling 1GHz vs 2GHz:
specbzip: 1.91
spechmmer: 1.995
speclibm: 1.501
specsjeng: 1.37
specmcf: 1.967

Όπως προκύπτει  με εξαιρεση τα b/m speclibm και specsjeng  εχουμε τέλειο scalling.
Για το speclib  τα cpi στα 2ghz ειναι περισσότερα κατα 1.33 φορες, τα read και write memory bandwidth είναι 1.5019 φορες
μεγαλυτερα ,το average icache overall miss latency ειναι μικροτερο κατα 1/1.336.Επίσης στα 1ghz εχω ελαχιστα περισσότερα hits
και ελαχιστα λιγότερα misses στη dcache.
Παρατηρόυμε οτι οι αναλογίες που φτιάξαμε ειναι κοντά στο scalling των χρόνων εκτέλεσης,καθως και οτι στα `1ghz εχω ορθότερη
προσπέλαση δεδομένων στην dcache.
Για το specsjeng   τα cpi στα 2ghz  ειναι 1.45 φορες περισσοτερα ,τα read και write bandwidth  1,37 φορες μεγαλύτερα,το average
icache overall miss latency μικροτερο κατα 1/1.29 .Τωρα ,στα 1 ghz  εχω ελαχιστα λιγοτερα hits και ελαχιστα περισσότερα misses.
Με την ιδια λογική  προκύπτει το αποτέλεσμα του scalling.
Συμεπερασματικά , η  δομή του benchmark απο άποψη κώδικα οδηγεί σε συγκεκριμένες προσβάσεις στην μνήμη και επομένως ο χρόνος
εκτέλεσης επηρεάζεται απο data buses ,latency of memory και απο την αρχιτεκτονική  των cache.



Πηγές:
https://en.wikipedia.org/wiki/Clock_rate
