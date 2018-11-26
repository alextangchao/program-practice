import csv


def cal(inname, outname):
    change = {"male": 1, "female": 2, "Q": 1, "C": 2, "S": 3}
    adds = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    data = []
    first = 1
    a = csv.reader(open(inname))
    for i in a:
        if first:
            first = 0
            continue
        """
        temp = []
        temp.append(i[0])
        temp.append(i[1])
        temp.append(i[2])
        temp.append(i[4])
        temp.append(i[5])
        temp.append(i[6])
        temp.append(i[7])
        temp.append(i[9])
        temp.append(i[11])
        """
        for k in range(len(i)):
            if i[k] in change:
                i[k] = str(change[i[k]])
            if i[k] == "":
                i[k] = "0"

        final = []
        final.append(i[0])
        final.append(i[1])
        print(i[2], i[5], i)
        # final.append(str(float(i[2]) * float(i[5])))
        final.append(i[2])
        final.append(i[4])
        final.append(i[5])
        # final.append(str(float(i[6]) + float(i[7])))
        final.append(i[6])
        final.append(i[7])
        final.append(i[9])
        final.append(i[11])
        # print(final)
        data.append(final)

    # data = power_up(data)

    # print(data)
    with open(outname, "w") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerows(data)


def power_up(line):
    for i in line:
        for k in i:
            # print(str(float(k)))
            i.append(str(int(k) ** 2))
    return line


cal("train.csv", "a.csv")
cal("test.csv", "b.csv")
