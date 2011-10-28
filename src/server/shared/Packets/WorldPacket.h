/*
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010-2011 Strawberry Project <http://www.strawberry-pr0jcts.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITYCORE_WORLDPACKET_H
#define TRINITYCORE_WORLDPACKET_H

#include "Common.h"
#include "ByteBuffer.h"
#include "Opcodes.h"

class WorldPacket : public ByteBuffer
{
    public:
                                                            // just container for later use
        WorldPacket()                                       : ByteBuffer(0), m_opcode(0)
        {
        }

        explicit WorldPacket(Opcodes enumVal, size_t res=200) : ByteBuffer(res)
        {
            m_opcode = LookupOpcodeNumber(enumVal);
        }

        explicit WorldPacket(uint32 opcode, size_t res = 200) : ByteBuffer(res), m_opcode(opcode)
        {
        }
        // copy constructor
        WorldPacket(const WorldPacket &packet) : ByteBuffer(packet), m_opcode(packet.m_opcode)
        {
        }

        void Initialize(Opcodes enumVal, size_t newres=200)
        {
            Initialize(LookupOpcodeNumber(enumVal), newres);
        }

        void Initialize(uint32 opcode, size_t newres = 200)
        {
            clear();
            _storage.reserve(newres);

            m_opcode = opcode;
        }

        uint32 GetOpcode() const { return m_opcode; }
        Opcodes GetOpcodeEnum() const { return LookupOpcodeEnum(m_opcode); }
        void SetOpcode(uint32 opcode) { m_opcode = opcode; }
        void SetOpcode(Opcodes enumVal) { m_opcode = LookupOpcodeNumber(enumVal); }

        void compress(Opcodes enumVal);

        void ReadByteMask(uint8& b)
        {
            b = readBit() ? 1 : 0;
        }
        void ReadByteSeq(uint8& b)
        {
            if (b != 0)
                b ^= read<uint8>();
        }

        void WriteByteMask(uint8 b)
        {
            writeBit(b);
        }
        void WriteByteSeq(uint8 b)
        {
            if (b != 0)
                append<uint8>(b ^ 1);
        }

    protected:
        uint32 m_opcode;
        void _compress(void* dst, uint32 *dst_size, const void* src, int src_size);
};
#endif