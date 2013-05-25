//////////////////////////////////////////////////////////////////////////////
// NoLifeClient - Part of the NoLifeStory project                           //
// Copyright (C) 2013 Peter Atashian                                        //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#include "NoLifeClient.hpp"
namespace NL {
    Obj::Obj(Node n)  {
        x = n["x"];
        y = n["y"];
        z = n["z"];
        flow = (int)n["flow"];
        rx = n["rx"];
        ry = n["ry"];
        flip = (int)n["f"];
        data = NXMap["Obj"][n["oS"] + ".img"][n["l0"]][n["l1"]][n["l2"]];
        //movetype = data["moveType"];
        //movew = data["moveW"];
        //moveh = data["moveH"];
        //movep = data["moveP"];
        //mover = data["moveR"];
        //repeat = data["repeat"];
    }
    void Obj::Render() {
        Node n = data[0];
        Sprite(n).Draw(x, y);
    }
    bool Obj::operator<(Obj const & o) const {
        return z < o.z;
    }
}